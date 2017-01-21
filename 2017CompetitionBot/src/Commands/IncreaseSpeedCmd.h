#ifndef IncreaseSpeedCmd_H
#define IncreaseSpeedCmd_H

#include "../CommandBase.h"

class IncreaseSpeedCmd : public CommandBase {
public:
	IncreaseSpeedCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IncreaseSpeedCmd_H
