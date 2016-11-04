#ifndef InputsSub_H
#define InputsSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InputsSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<DigitalInput> limitSwitch1In;
	std::unique_ptr<DigitalInput> limitSwitch2In;
public:
	InputsSub();
	void InitDefaultCommand();
	bool isSwitchHit(int switchPort);
};

#endif
