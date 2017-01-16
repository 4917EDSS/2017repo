#ifndef DriveStraightCmd_H
#define DriveStraightCmd_H

#include "../CommandBase.h"

class DriveStraightCmd : public CommandBase {
public:
	DriveStraightCmd(int distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float leftSpeed=1.0;
	float rightSpeed=1.0;
	int endDistance;
};

#endif  // DriveStraightCmd_H
