#ifndef SilkyRotateCmd_H
#define SilkyRotateCmd_H

#include "../CommandBase.h"
#include "../Components/SilkyRotationManager.h"

class SilkyRotateCmd : public CommandBase {
private:
	SilkyRotationManager srm;
	float timeFromLastMove;
	float lastMoveTime;
public:
	SilkyRotateCmd(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SilkyRotateCmd_H
