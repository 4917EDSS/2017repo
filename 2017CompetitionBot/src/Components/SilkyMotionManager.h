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

// Use these macros to specify silky motion in increments rather than a running total
// e.g. std::vector<double> {0, 1425, 2400, 3450} would be SILKY4(0, 1425, 975, 1050)
#define SILKY3(a, b, c)			std::vector<double> {(a), ((a)+(b)), ((a)+(b)+(c))}
#define SILKY4(a, b, c, d)		std::vector<double> {(a), ((a)+(b)), ((a)+(b)+(c)), ((a)+(b)+(c)+(d))}
#define SILKY5(a, b, c, d, e)	std::vector<double> {(a), ((a)+(b)), ((a)+(b)+(c)), ((a)+(b)+(c)+(d)), ((a)+(b)+(c)+(d)+(e))}

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
	//Debug
	double KvL, KvR, KaL, KaR, KpL, KpR, KdL, KdR;
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
