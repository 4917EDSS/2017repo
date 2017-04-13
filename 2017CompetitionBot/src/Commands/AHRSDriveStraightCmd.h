#ifndef AHRSDriveStraightCmd_H
#define AHRSDriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AHRSDriveStraightCmd: public CommandBase
{
private:
	int distanceBlue;
	int distanceRed;
	int targetDistance;
	float targetSpeed;
	float timeFromLastMove;
	float lastMoveTime;
public:
	AHRSDriveStraightCmd(int distance);
	AHRSDriveStraightCmd(int distanceBlue, int distanceRed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
