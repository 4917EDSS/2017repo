/*
 * SilkyMotionManager.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: sam_000
 */

#include <Components/SilkyMotionManager.h>
#include <cmath>
#include <iostream>

	SilkyMotionManager::SilkyMotionManager(std::vector<double> leftWheel, std::vector<double> rightWheel,
      double maxAccel, double maxDecel, double maxVel,
			double stoppingDistanceTolerance, double stoppingSpeedTolerance) :
    maxAccel(maxAccel), maxDecel(maxDecel), maxVel(maxVel),
		stoppingDistanceTolerance(stoppingDistanceTolerance),
		stoppingSpeedTolerance(stoppingSpeedTolerance), startTime(-1),
		Kv(1/maxVel), Ka(0), Kp(0), Kd(0), lastLeftError(0), lastRightError(0),
    lastTime(0){

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

  double timeDecelerating = t - timeToMaxVel - timeAtMaxVel;

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
  if (stoppingLocationLeft > stoppingLocationRight) {
    left = getGenerallyFasterSide(stoppingLocationLeft, timeSinceStart);
    right = getGenerallySlowerSide(stoppingLocationLeft, timeSinceStart);
  } else {
    left = getGenerallySlowerSide(stoppingLocationRight, timeSinceStart);
    right = getGenerallyFasterSide(stoppingLocationRight, timeSinceStart);
  }

  leftError = left.dis - currentLeftPos;
  leftErrorDeriv = (leftError - lastLeftError) / (timeSinceStart - lastTime);
  rightError = right.dis - currentRightPos;
  rightErrorDeriv = (rightError - lastRightError) / (timeSinceStart - lastTime);

  lastLeftError = leftError;
  lastRightError = rightError;
  lastTime = timeSinceStart;

  leftSetpoint = Kv * left.vel
    + Ka * left.accel
    + Kp * leftError
    + Kd * leftErrorDeriv;
  rightSetpoint = Kv * right.vel
    + Ka * right.accel
    + Kp * rightError
    + Kd * rightErrorDeriv;
  return std::make_pair(leftSetpoint, rightSetpoint);
}

bool SilkyMotionManager::isFinished(double leftPos, double leftVel, double rightPos, double rightVel);
	if(abs(leftPos - stoppingLocationLeft) < stoppingDistanceTolerance
      && abs(rightPos - stoppingLocationRight) < stoppingDistanceTolerance
      && abs(leftVel) < stoppingSpeedTolerance
      && abs(rightVel) < stoppingSpeedTolerance) {
		return true;
	} else {
		return false;
	}
}
