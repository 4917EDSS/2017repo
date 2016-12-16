#ifndef StopCmd_H
#define StopCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopCmd: public CommandBase
{
public:
	StopCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
