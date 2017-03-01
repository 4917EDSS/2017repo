#ifndef KillEverythingCmd_H
#define KillEverythingCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class KillEverythingCmd : public CommandBase {
public:
	KillEverythingCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // KillEverythingCmd_H
