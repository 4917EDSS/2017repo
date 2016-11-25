#ifndef IntakeWithJoystickCmd_H
#define IntakeWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeWithJoystickCmd: public CommandBase
{
public:
	IntakeWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
