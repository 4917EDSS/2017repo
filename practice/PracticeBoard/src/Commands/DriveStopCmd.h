#ifndef DriveStopCmd_H
#define DriveStopCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStopCmd: public CommandBase
{
public:
	DriveStopCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
