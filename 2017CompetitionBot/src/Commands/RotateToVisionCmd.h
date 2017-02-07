#ifndef RotateToVisionCmd_H
#define RotateToVisionCmd_H

#include "../CommandBase.h"

class RotateToVisionCmd : public CommandBase {
public:
	RotateToVisionCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateToVisionCmd_H
