#ifndef RunPickupCmd_H
#define RunPickupCmd_H

#include "../CommandBase.h"

class RunPickupCmd : public CommandBase {
public:
	RunPickupCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunPickupCmd_H
