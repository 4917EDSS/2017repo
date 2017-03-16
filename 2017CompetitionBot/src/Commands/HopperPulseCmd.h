#ifndef HopperPulseCmd_H
#define HopperPulseCmd_H

#include "../CommandBase.h"

class HopperPulseCmd : public CommandBase {
public:
	HopperPulseCmd(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float nextEventTime;
	float totalTime;
	bool openHopperNext;
};

#endif  // HopperPulseCmd_H
