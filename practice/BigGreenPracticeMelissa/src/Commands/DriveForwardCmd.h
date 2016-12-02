#ifndef DriveForwardCmd_H
#define DriveForwardCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForwardCmd: public CommandBase
{
public:
	DriveForwardCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
