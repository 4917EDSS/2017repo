#ifndef OpenGearFlapsHeldCmd_H
#define OpenGearFlapsHeldCmd_H

#include "../CommandBase.h"

class OpenGearFlapsHeldCmd : public CommandBase {
public:
	OpenGearFlapsHeldCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenGearFlapsHeldCmd_H
