#ifndef ExpandHopperCmd_H
#define ExpandHopperCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExpandHopperCmd : public CommandBase {
public:
	ExpandHopperCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShrinkHopperCmd_H
