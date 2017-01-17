#ifndef LiftCmd_H
#define LiftCmd_H

#include "../CommandBase.h"

class LiftCmd : public CommandBase {
public:
	LiftCmd(int speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int setSpeed;
};

#endif  // LiftCmd_H
