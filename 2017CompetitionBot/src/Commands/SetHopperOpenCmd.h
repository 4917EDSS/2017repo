#ifndef SetHopperOpenCmd_H
#define SetHopperOpenCmd_H

#include "../CommandBase.h"

class SetHopperOpenCmd : public CommandBase {
private:
	bool open;
public:
	SetHopperOpenCmd(bool open = true);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetHopperOpenCmd_H
