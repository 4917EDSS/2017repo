#ifndef StopDriveTrainCmd_H
#define StopDriveTrainCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopDriveTrainCmd: public CommandBase
{
public:
	StopDriveTrainCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
