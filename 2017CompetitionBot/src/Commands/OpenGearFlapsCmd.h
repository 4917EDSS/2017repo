#ifndef OpenGearFlapsCmd_H
#define OpenGearFlapsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class OpenGearFlapsCmd : public CommandBase {
private:
	bool open;
public:
	OpenGearFlapsCmd();
	OpenGearFlapsCmd(bool b);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenGearFlapsCmd_H
