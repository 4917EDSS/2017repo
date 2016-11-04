#ifndef HoldButtonToTurnCmd_H
#define HoldButtonToTurnCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class HoldButtonToTurnCmd: public CommandBase
{
public:
	HoldButtonToTurnCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
