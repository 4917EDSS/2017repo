#ifndef SilkyDriveStraightCmd_H
#define SilkyDriveStraightCmd_H

#include "../CommandBase.h"
#include "Components/SilkyMotionManager.h"

class SilkyDriveStraightCmd : public CommandBase {
private:
	SilkyMotionManager smm;
public:
	SilkyDriveStraightCmd(float targetDis);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SilkyDriveStraightCmd_H
