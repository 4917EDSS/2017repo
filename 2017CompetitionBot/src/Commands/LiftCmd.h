#ifndef LiftCmd_H
#define LiftCmd_H

#include "../CommandBase.h"

class LiftCmd : public CommandBase {
public:
	LiftCmd(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double setSpeed;
};

#endif  // LiftCmd_H
