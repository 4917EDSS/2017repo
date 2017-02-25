/*
 * SilkyMotionManager.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: sam_000
 */

#include <Components/SilkyMotionManager.h>
#include <cmath>
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>

SilkyMotionManager::SilkyMotionManager(std::vector<double> leftWheel, std::vector<double> rightWheel,
		double maxAccel, double maxDecel, double maxVel,
		double stoppingDistanceTolerance, double stoppingSpeedTolerance) :
		maxAccel(maxAccel), maxDecel(maxDecel), maxVel(maxVel),
		stoppingDistanceTolerance(stoppingDistanceTolerance),
		stoppingSpeedTolerance(stoppingSpeedTolerance), startTime(-1),
		Kv(0), Ka(0), Kp(0), Kd(0), lastLeftError(0), lastRightError(0),
		lastTime(0){
	negative = leftWheel[leftWheel.size()-1] < 0;
	straight = true;
	for(unsigned int i = 0; i < leftWheel.size(); i++) {
		if (leftWheel[i] != rightWheel[i]) {
			straight = false;
			break;
		}
	}
	if (negative) {
		for(unsigned int i = 0; i < leftWheel.size(); i++) {
			leftWheel[i] = -leftWheel[i];
		}
		for(unsigned int i = 0; i < rightWheel.size(); i++) {
			rightWheel[i] = -rightWheel[i];
		}
	}
	stoppingLocationLeft = leftWheel[leftWheel.size()-1];
	stoppingLocationRight = rightWheel[rightWheel.size()-1];
	if (stoppingLocationLeft > stoppingLocationRight) {
		spline.set_points(leftWheel, rightWheel);
	} else {
		spline.set_points(rightWheel, leftWheel);
	}
}

// Returns the current path info for TRAPEZOIDAL side
PathInfo SilkyMotionManager::getGenerallyFasterSide(double maxDist, double t) {
	//Assuming no crazy curves in spline, and giving reasonable headroom for acceleration + speed. We will tell program "max" is actually lower than max, since we are only programming for the left side. If the right side needs to turn faster than the right, the combination of a smaller max and a reasonable curvature will allow it to get ahead.
	//This means the left side will go "as fast as possible" in this model.
	double adjustedMaxVel = maxVel;

	double disToMaxVel = 0.5 * pow(maxVel, 2) / maxAccel;
	double disToZeroVel = 0.5 * pow(maxVel, 2) / maxDecel;
	if (disToMaxVel + disToZeroVel > maxDist) {
		// Don't get to full speed, so triangle instead of trapezoid
		// d_accel = v^2/(2*a_accel)
		// d_decel = v^2/(2*a_decel)
		// d_total = v^2/(2*a_accel) + v^2/(2*a_decel)
		// Rearranging for v gives
		// v = sqrt(2*d_total*a_accel*a_decel/(a_accel + a_decel))
		adjustedMaxVel = sqrt(2 * maxDist * maxAccel * maxDecel / (maxAccel + maxDecel));
		disToMaxVel = 0.5 * pow(adjustedMaxVel, 2) / maxAccel;
		disToZeroVel = 0.5 * pow(adjustedMaxVel, 2) / maxDecel;
	}
	double timeToMaxVel = adjustedMaxVel / maxAccel;
	if (t <= timeToMaxVel) {
		double currentDis = 0.5 * maxAccel * pow(t, 2);
		double currentVel = maxAccel * t;
		return PathInfo{currentDis, currentVel, maxAccel};
	}
	double timeAtMaxVel = (maxDist - disToMaxVel - disToZeroVel) / adjustedMaxVel;
	if (t <= timeToMaxVel + timeAtMaxVel) {
		double currentDis = disToMaxVel + ((t - timeToMaxVel) * adjustedMaxVel);
		return PathInfo{currentDis, adjustedMaxVel, 0};
	}

	double timeToZero = adjustedMaxVel / maxDecel;
	double timeDecelerating = t - timeToMaxVel - timeAtMaxVel;

	if (timeDecelerating >= timeToZero) {
		return PathInfo{maxDist, 0, 0};
	}

	// x_f = x_i + vt + 0.5at^2
	double currentDis = disToMaxVel + (timeAtMaxVel * adjustedMaxVel)
    		+ (adjustedMaxVel * timeDecelerating)
			- (0.5 * maxDecel * pow(timeDecelerating, 2));
	double currentVel = adjustedMaxVel - (maxDecel * timeDecelerating);
	return PathInfo{currentDis, currentVel, -maxDecel};
}

PathInfo SilkyMotionManager::getGenerallySlowerSide(double maxFasterSideDist, double t) {
	const double deltaT = 0.00001;
	PathInfo beforeFast = getGenerallyFasterSide(maxFasterSideDist, t - deltaT);
	PathInfo currentFast = getGenerallyFasterSide(maxFasterSideDist, t);
	PathInfo afterFast = getGenerallyFasterSide(maxFasterSideDist, t + deltaT);

	// Looking up where side should be according to spline
	double before = spline(beforeFast.dis);
	double current = spline(currentFast.dis);
	double after = spline(afterFast.dis);

	if (currentFast.dis == maxFasterSideDist && currentFast.accel == 0.0 && currentFast.vel == 0.0) {
		return PathInfo{current, 0, 0};
	}

	// After and before are 2 deltaTs apart
	double currentVel = (after - before) / (2*deltaT);

	double beforeVel = (current - before) / deltaT;
	double afterVel = (after - current) / deltaT;
	double currentAccel = (afterVel - beforeVel) / deltaT;

	return PathInfo{current, currentVel, currentAccel};
}

void SilkyMotionManager::setKvKaKpKd(double v, double a, double p, double d) {
	Kv = v;
	Ka = a;
	Kp = p;
	Kd = d;
}
void SilkyMotionManager::reset() {
	startTime = -1;
	lastLeftError = 0;
	lastRightError = 0;
	lastTime = 0;
}

double SilkyMotionManager::getTimeSinceStart() {
	double currTime = ((double) GetFPGATime()) / 1000000.0;
	if(startTime < 0) {
		startTime = currTime;
	}
	return currTime - startTime;
}

std::pair<double, double> SilkyMotionManager::execute(double currentLeftPos, double currentRightPos) {
	float timeSinceStart = getTimeSinceStart();
	PathInfo left;
	PathInfo right;

	std::cout << "negative" << negative << std::endl;
	if (straight) {
		left = getGenerallyFasterSide(stoppingLocationLeft, timeSinceStart);
		right = getGenerallyFasterSide(stoppingLocationLeft, timeSinceStart);
	} else if (stoppingLocationLeft > stoppingLocationRight) {
		left = getGenerallyFasterSide(stoppingLocationLeft, timeSinceStart);
		right = getGenerallySlowerSide(stoppingLocationLeft, timeSinceStart);
	} else {
		left = getGenerallySlowerSide(stoppingLocationRight, timeSinceStart);
		right = getGenerallyFasterSide(stoppingLocationRight, timeSinceStart);
	}
	if (negative) {
		left.dis = -left.dis;
		left.vel = -left.vel;
		left.accel = -left.accel;
		right.dis = -right.dis;
		right.vel = -right.vel;
		right.accel = -right.accel;
	}

	double leftError = left.dis - currentLeftPos;
	double leftErrorDeriv = (leftError - lastLeftError) / (timeSinceStart - lastTime);
	double rightError = right.dis - currentRightPos;
	double rightErrorDeriv = (rightError - lastRightError) / (timeSinceStart - lastTime);
	SmartDashboard::PutNumber("right target dis",right.dis);
	SmartDashboard::PutNumber("left target dis",left.dis);
	SmartDashboard::PutNumber("right target vel",right.vel*Kv);
	SmartDashboard::PutNumber("left target vel",left.vel*Kv);
	SmartDashboard::PutNumber("right target accel",right.accel*Ka);
	SmartDashboard::PutNumber("left target accel",left.accel*Ka);
	SmartDashboard::PutNumber("right error",rightError);
	SmartDashboard::PutNumber("left error",leftError);

	lastLeftError = leftError;
	lastRightError = rightError;
	lastTime = timeSinceStart;


	double leftMotorValue = Kv * left.vel
			+ Ka * left.accel
			+ Kp * leftError
			+ Kd * leftErrorDeriv;
	double rightMotorValue = Kv * right.vel
			+ Ka * right.accel
			+ Kp * rightError
			+ Kd * rightErrorDeriv;
	return std::make_pair(leftMotorValue, rightMotorValue);
}

bool SilkyMotionManager::isFinished(double leftPos, double leftVel, double rightPos, double rightVel){
	SmartDashboard::PutNumber("left velocity",leftVel);
	SmartDashboard::PutNumber("right velocity",rightVel);
	// Taking abs of leftPos and rightPos because stoppingLocations are always positive, but if we are going backwards leftpos might be negative
	if(abs(abs(leftPos) - stoppingLocationLeft) < stoppingDistanceTolerance
			&& abs(abs(rightPos) - stoppingLocationRight) < stoppingDistanceTolerance
			&& abs(leftVel) < stoppingSpeedTolerance
			&& abs(rightVel) < stoppingSpeedTolerance) {
		return true;
	} else {
		return false;
	}
}

void SilkyMotionManager::setAlliance(frc::DriverStation::Alliance alliance) {
	if(alliance == frc::DriverStation::Alliance::kRed) {
		double temp = stoppingLocationLeft;
		stoppingLocationLeft = stoppingLocationRight;
		stoppingLocationRight = temp;
	}
}

