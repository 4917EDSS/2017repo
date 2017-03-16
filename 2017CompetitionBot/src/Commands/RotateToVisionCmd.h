#ifndef RotateToVisionCmd_H
#define RotateToVisionCmd_H

#include "../CommandBase.h"

class RotateToVisionCmd : public CommandBase {
private:
	double ComputeDeviation();
	double turnDegrees;		// How many degrees the robot has to rotate to be centered on the object of interest
	int minTargets;			// Minimum number of vision targets needed to properly calculate the center of the object of interest
public:
	RotateToVisionCmd(int minVisionTargets);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateToVisionCmd_H
