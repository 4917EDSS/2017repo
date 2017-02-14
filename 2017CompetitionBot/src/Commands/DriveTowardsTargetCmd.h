#ifndef DriveTowardsTargetCmd_H
#define DriveTowardsTargetCmd_H

#include "../CommandBase.h"

class DriveTowardsTargetCmd : public CommandBase {
public:
	DriveTowardsTargetCmd(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double driveSpeed = 0.0;
};

#endif  // DriveTowardsTargetCmd_H
