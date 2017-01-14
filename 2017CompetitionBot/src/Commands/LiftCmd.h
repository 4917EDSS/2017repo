#ifndef LiftCmd_H
#define LiftCmd_H

#include "../CommandBase.h"

class LiftCmd : public CommandBase {
public:
	LiftCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftCmd_H
