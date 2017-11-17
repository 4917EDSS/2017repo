#ifndef ToggleTalonCmd_H
#define ToggleTalonCmd_H

#include "../CommandBase.h"

class ToggleTalonCmd : public CommandBase {
public:
	ToggleTalonCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleTalonCmd_H
