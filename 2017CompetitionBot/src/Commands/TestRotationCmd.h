#ifndef TestRotationCmd_H
#define TestRotationCmd_H

#include "../CommandBase.h"

class TestRotationCmd : public CommandBase {
public:
	TestRotationCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TestRotationCmd_H
