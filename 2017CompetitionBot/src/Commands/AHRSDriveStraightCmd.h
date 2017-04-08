#ifndef AHRSDriveStraightCmd_H
#define AHRSDriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AHRSDriveStraightCmd: public CommandBase
{
private:
	int targetDistance;
	float targetSpeed;
public:
	AHRSDriveStraightCmd(int distance, float speed = 0.7);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
