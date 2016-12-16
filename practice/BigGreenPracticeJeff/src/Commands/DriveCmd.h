#ifndef DriveCmd_H
#define DriveCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCmd: public CommandBase
{
public:
	DriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
