#ifndef ToggleShifterCmd_H
#define ToggleShifterCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleShifterCmd : public CommandBase {
public:
	ToggleShifterCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleShifterCmd_H
