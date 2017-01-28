/*
 * SilkyMotionManager.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: sam_000
 */

#include <Components/SilkyMotionManager.h>
#include <iostream>

SilkyMotionManager::SilkyMotionManager(float targetPos, float accel, float decel,
		float powerAccel, float powerDecel, float stoppingDistanceTolerance,
		float stoppingSpeedTolerance) : targetPos(targetPos), accel(accel),
		decel(decel), powerAccel(powerAccel), powerDecel(powerDecel),
		stoppingDistanceTolerance(stoppingDistanceTolerance),
		stoppingSpeedTolerance(stoppingSpeedTolerance){
	timeOfAccel = sqrt(2*targetPos/(1/accel + 1/decel))/accel;
	timeOfDecel = sqrt(2*targetPos/(1/accel + 1/decel))/decel;
	std::cout << timeOfAccel << std::endl;
	std::cout << timeOfDecel << std::endl;
	startTime = -1;
}

float SilkyMotionManager::getTimeSinceStart() {
	float currTime = ((float) GetFPGATime()) / 1000000.0;
	if(startTime < 0) {
		startTime = currTime;
	}
	return currTime - startTime;
}

float SilkyMotionManager::execute(float currentPos) {
	//float currentDistance = fabs(currentPos - targetPos);
	float timeSinceStart = getTimeSinceStart();
	if(timeSinceStart<timeOfAccel){
		return powerAccel;
	} else {
		return powerDecel;
	}

}

bool SilkyMotionManager::isFinished() {
	float timeSinceStart = getTimeSinceStart();
	if(timeSinceStart < timeOfAccel + timeOfDecel) {
		return false;
	} else {
		return true;
	}
}
