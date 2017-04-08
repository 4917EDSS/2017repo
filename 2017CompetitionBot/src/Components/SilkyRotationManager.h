/*
 * SilkyRotationManager.h
 *
 *  Created on: Apr 5, 2017
 *      Author: egaudet
 */

#ifndef SRC_COMPONENTS_SILKYROTATIONMANAGER_H_
#define SRC_COMPONENTS_SILKYROTATIONMANAGER_H_

struct RotationInfo {
	double dis;
	double vel;
	double accel;
};

class SilkyRotationManager {
private:
	double targetRotationAngle;
	bool negative;

	double maxAccel, maxDecel, maxVel;
	double stoppingDistanceTolerance, stoppingSpeedTolerance;
	double Kv, Ka, Kp, Kd;

	double startTime;
	double lastError;
	double lastTime;

	double getTimeSinceStart();
	struct RotationInfo getRotationInfo(double angle, double t);

public:
	SilkyRotationManager(double angle);
	void reset();
	double execute(double currentAngle);
	bool isFinished(double currentAngle);
};



#endif /* SRC_COMPONENTS_SILKYROTATIONMANAGER_H_ */
