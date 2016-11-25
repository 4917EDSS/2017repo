#ifndef ToggleJawsInOutCmd_H
#define ToggleJawsInOutCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleJawsInOutCmd: public CommandBase
{
public:
	ToggleJawsInOutCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
