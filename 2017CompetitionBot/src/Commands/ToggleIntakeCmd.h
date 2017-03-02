#ifndef ToggleIntakeCmd_H
#define ToggleIntakeCmd_H

#include "../CommandBase.h"

class ToggleIntakeCmd : public CommandBase {
public:
	ToggleIntakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleIntakeCmd_H
