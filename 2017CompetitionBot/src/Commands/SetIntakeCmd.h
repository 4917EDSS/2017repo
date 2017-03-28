#ifndef SetIntakeCmd_H
#define SetIntakeCmd_H

#include "../CommandBase.h"

class SetIntakeCmd : public CommandBase {
public:
	SetIntakeCmd(bool newVal);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool intake;
};

#endif  // SetIntakeCmd_H
