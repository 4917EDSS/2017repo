#ifndef LiftWithJoystickCmd_H
#define LiftWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftWithJoystickCmd: public CommandBase
{
public:
	LiftWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
