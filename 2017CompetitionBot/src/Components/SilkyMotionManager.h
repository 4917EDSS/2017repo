/*
 * SilkyMotionManager.h
 *
 *  Created on: Jan 28, 2017
 *      Author: sam_000
 *
 *  Thanks 2702! :)
 */

#ifndef SRC_COMPONENTS_SILKYMOTIONMANAGER_H_
#define SRC_COMPONENTS_SILKYMOTIONMANAGER_H_

#include <vector>
#include <utility>
#include "WPILib.h"

class SilkyMotionManager {
private:
	std::vector<std::pair<float, float> > history;
	float targetPos;
	float timeOfAccel;
	float timeOfDecel;
	float accel;
	float decel;
	float powerAccel;
	float powerDecel;
	float stoppingDistanceTolerance;
	float stoppingSpeedTolerance;
	float startTime;

	float getTimeSinceStart();

public:
	SilkyMotionManager(float targetPos, float accel, float decel,
			float powerAccel, float powerDecel, float stoppingDistanceTolerance,
			float stoppingSpeedTolerance);
	float execute(float currentPos);
	bool isFinished();
};

#endif /* SRC_COMPONENTS_SILKYMOTIONMANAGER_H_ */
