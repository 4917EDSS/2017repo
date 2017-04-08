/*
 * SilkyRotationManager.cpp
 *
 * A simplified version of SilkyMotionManager for rotating the robot along its center of rotation
 * using an AHRS device for feedback (e.g. NAVX) rather than wheel encoders.
 *
 *  Created on: Apr 5, 2017
 *      Author: egaudet
 */

#include <iostream>
#include <cmath>
#include "WPILib.h"
#include "SilkyRotationManager.h"

// Robot-specific constants - all in degrees, seconds
// To make this component more generic, these values should be passed-in (via constructor) but
// to make implementation and compiles faster, define them here.
constexpr double MAX_ANGULAR_ACCEL = 333; 					// deg/s^2
constexpr double MAX_ANGULAR_DECEL = 665;					// deg/s^2
constexpr double MAX_ANGULAR_VEL = 166; 					// deg/s
constexpr double STOPPING_ANGULAR_DISTANCE_TOLERANCE = 2;	// deg			// TODO: Set correct value
constexpr double STOPPING_ANGULAR_SPEED_TOLERANCE = 1;		// deg/s		// TODO: Set correct value
constexpr double SILKY_ROT_KV = (1.0/MAX_ANGULAR_ACCEL)*0.87;				// TODO: Set correct value
constexpr double SILKY_ROT_KA = (1.0/MAX_ANGULAR_DECEL)*0.485;				// TODO: Set correct value
constexpr double SILKY_ROT_KP = 0.010;										// TODO: Set correct value
constexpr double SILKY_ROT_KI = 0.00001;	//not used
constexpr double SILKY_ROT_KD = 0.00002;									// TODO: Set correct value


SilkyRotationManager::SilkyRotationManager(double angle)
{
	if( angle < 0 )	{
		negative = true;
		targetRotationAngle = -angle;
	}
	else {
		negative = false;
		targetRotationAngle = angle;
	}

	maxAccel = MAX_ANGULAR_ACCEL;
	maxDecel = MAX_ANGULAR_DECEL;
	maxVel = MAX_ANGULAR_VEL;

	stoppingDistanceTolerance = STOPPING_ANGULAR_DISTANCE_TOLERANCE;
	stoppingSpeedTolerance = STOPPING_ANGULAR_SPEED_TOLERANCE;

	Kv = SILKY_ROT_KV;
	Ka = SILKY_ROT_KA;
	Kp = SILKY_ROT_KP;
	Kd = SILKY_ROT_KD;

	startTime = -1;
	lastTime = 0;
	lastError = 0;
}

// Setup for a new run
void SilkyRotationManager::reset(){
	targetRotationAngle = 0;

	startTime = -1;
	lastTime = 0;
	lastError = 0;
}

double SilkyRotationManager::getTimeSinceStart() {
	// FPGA time is in microseconds (us)
	double currTime = ((double) GetFPGATime()) / 1000000.0;
	if(startTime < 0) {
		startTime = currTime;
	}
	return currTime - startTime;
}

// Determine where we are on the acceleration/constant-velocity/deceleration path
struct RotationInfo SilkyRotationManager::getRotationInfo(double targetAngleDis, double t) {
	// Notes:
	//    - Distance is angular-distance in degrees
	//    - Velocity is angular-velocity in deg/s
	//    - Acceleration is angular-acceleration in deg/s^2

	// Determine how many degrees it takes for the robot to go from a stop to full rotation speed and then back to a stop
	double adjustedMaxVel = maxVel;
	double disToMaxVel = 0.5 * pow(maxVel, 2) / maxAccel;	// from vf^2 = vi^2 + 2*a*d where vi = 0, vf is max angular velocity and a is max angular acceleration
	double disToZeroVel = 0.5 * pow(maxVel, 2) / maxDecel;

	// Check if the robot will need to get up to full speed or not
	if (disToMaxVel + disToZeroVel > targetAngleDis) {
		// Don't get to full speed, so triangle velocity profile (accel then decel) instead of trapezoid (accel, constant velocity, decel)
		// d_accel = v^2/(2*a_accel)
		// d_decel = v^2/(2*a_decel)
		// d_total = v^2/(2*a_accel) + v^2/(2*a_decel)
		// Rearranging for v gives
		// v = sqrt(2*d_total*a_accel*a_decel/(a_accel + a_decel))
		adjustedMaxVel = sqrt(2 * targetAngleDis * maxAccel * maxDecel / (maxAccel + maxDecel));
		disToMaxVel = 0.5 * pow(adjustedMaxVel, 2) / maxAccel;
		disToZeroVel = 0.5 * pow(adjustedMaxVel, 2) / maxDecel;
	}

	double timeToMaxVel = adjustedMaxVel / maxAccel;
	if (t <= timeToMaxVel) {
		// Accelerating
		double currentDis = 0.5 * maxAccel * pow(t, 2);
		double currentVel = maxAccel * t;
		return RotationInfo{currentDis, currentVel, maxAccel};
	}

	double timeAtMaxVel = (targetAngleDis - disToMaxVel - disToZeroVel) / adjustedMaxVel;
	if (t <= timeToMaxVel + timeAtMaxVel) {
		// Constant velocity
		double currentDis = disToMaxVel + ((t - timeToMaxVel) * adjustedMaxVel);
		return RotationInfo{currentDis, adjustedMaxVel, 0};
	}

	double timeToZero = adjustedMaxVel / maxDecel;
	double timeDecelerating = t - timeToMaxVel - timeAtMaxVel;

	if (timeDecelerating >= timeToZero) {
		// Stopped
		return RotationInfo{targetAngleDis, 0, 0};
	}

	// Decelerating
	// x_f = x_i + vt + 0.5at^2
	double currentDis = disToMaxVel + (timeAtMaxVel * adjustedMaxVel)
    		+ (adjustedMaxVel * timeDecelerating)
			- (0.5 * maxDecel * pow(timeDecelerating, 2));
	double currentVel = adjustedMaxVel - (maxDecel * timeDecelerating);
	return RotationInfo{currentDis, currentVel, -maxDecel};
}


// Using the current angle, target angle and current path information, this method returns the
// motor power that should be applied.  The same power should be applied to both left and right
// motors but with one being the negative of the other.
//
// e.g. execute returns 0.75 ->  Set left to 0.75, right to -0.75
//
// If the wheels need significantly different power to run the same speed, the power value could
// be fed to a motor balancer.
double SilkyRotationManager::execute(double currentAngle) {
	float timeSinceStart = getTimeSinceStart();
	RotationInfo rotationInfo;

	rotationInfo = getRotationInfo(targetRotationAngle, timeSinceStart);

	if (negative) {
		rotationInfo.dis = -rotationInfo.dis;
		rotationInfo.vel = -rotationInfo.vel;
		rotationInfo.accel = -rotationInfo.accel;
	}

	double error = rotationInfo.dis - currentAngle;
	double errorDeriv = (error - lastError) / (timeSinceStart - lastTime);

	lastError = error;
	lastTime = timeSinceStart;

	double power = Kv * rotationInfo.vel
				 + Ka * rotationInfo.accel
				 + Kp * error
				 + Kd * errorDeriv;

	return power;
}

bool SilkyRotationManager::isFinished(double currentAngle) {

	// Get the correct target angle
	double actualTargetAngle = negative ? -targetRotationAngle : targetRotationAngle;

	// TODO:  Check if angular speed is below threshold (meaning we've mostly stopped so should quit)
	if( fabs(actualTargetAngle - currentAngle) < stoppingDistanceTolerance ) {
		return true;
	} else {
		return false;
	}
}

