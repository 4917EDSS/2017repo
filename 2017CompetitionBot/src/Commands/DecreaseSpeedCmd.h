#ifndef DecreaseSpeedCmd_H
#define DecreaseSpeedCmd_H

#include "../CommandBase.h"

class DecreaseSpeedCmd : public CommandBase {
public:
	DecreaseSpeedCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DecreaseSpeedCmd_H
