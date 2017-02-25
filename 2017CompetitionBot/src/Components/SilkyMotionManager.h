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
#include "spline.h"
#include "WPILib.h"

struct PathInfo {
	double dis;
	double vel;
	double accel;
};

class SilkyMotionManager {
private:
	double maxAccel, maxDecel, maxVel;
	double stoppingDistanceTolerance, stoppingSpeedTolerance;
	double startTime;
	double Kv, Ka, Kp, Kd;
	double stoppingLocationLeft, stoppingLocationRight;
	double lastLeftError;
	double lastRightError;
	double lastTime;
	bool negative;
	bool straight;
	bool called;
	tk::spline spline;

	double getTimeSinceStart();
	PathInfo getGenerallyFasterSide(double maxDist, double t);
	PathInfo getGenerallySlowerSide(double maxFasterSideDist, double t);

public:
	SilkyMotionManager(std::vector<double> leftWheel, std::vector<double> rightWheel,
			double maxAccel, double maxDecel, double maxVel,
			double stoppingDistanceTolerance, double stoppingSpeedTolerance);
	void setKvKaKpKd(double v, double a, double p, double d);
	std::pair<double, double> execute(double currentLeftPos, double currentRightPos); // returns left speed, right speed to set motors
	bool isFinished(double leftPos, double leftVel, double rightPos, double rightVel);
	void reset();
	void setAlliance(frc::DriverStation::Alliance alliance);
};

#endif /* SRC_COMPONENTS_SILKYMOTIONMANAGER_H_ */
