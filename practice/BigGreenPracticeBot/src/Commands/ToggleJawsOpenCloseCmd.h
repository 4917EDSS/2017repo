#ifndef ToggleJawsOpenCloseCmd_H
#define ToggleJawsOpenCloseCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleJawsOpenCloseCmd: public CommandBase
{
public:
	ToggleJawsOpenCloseCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
