#ifndef AHRSDriveStraightCmd_H
#define AHRSDriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AHRSDriveStraightCmd: public CommandBase
{
private:
	int targetDistance;
	float targetSpeed;
	float timeFromLastMove;
	float lastMoveTime;
public:
	AHRSDriveStraightCmd(int distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
