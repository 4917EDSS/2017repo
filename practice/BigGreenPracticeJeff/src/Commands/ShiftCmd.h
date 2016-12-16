#ifndef ShiftCmd_H
#define ShiftCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftCmd: public CommandBase
{
public:
	ShiftCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
