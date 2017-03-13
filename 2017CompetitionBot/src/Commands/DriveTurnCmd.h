#ifndef DriveTurnCmd_H
#define DriveTurnCmd_H

#include "../CommandBase.h"
#include "RobotMap.h"

class DriveTurnCmd : public CommandBase {
public:
	DriveTurnCmd(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double turnDegrees;
};

#endif  // DriveTurnCmd_H
