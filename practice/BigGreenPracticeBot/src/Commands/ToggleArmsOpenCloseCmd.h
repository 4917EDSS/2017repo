#ifndef ToggleArmsOpenCloseCmd_H
#define ToggleArmsOpenCloseCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleArmsOpenCloseCmd: public CommandBase
{
public:
	ToggleArmsOpenCloseCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
