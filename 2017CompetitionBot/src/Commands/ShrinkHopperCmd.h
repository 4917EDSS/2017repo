#ifndef ShrinkHopperCmd_H
#define ShrinkHopperCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShrinkHopperCmd : public CommandBase {
public:
	ShrinkHopperCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShrinkHopperCmd_H
