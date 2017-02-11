#ifndef AgitatorSub_H
#define AgitatorSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"

class AgitatorSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//std::shared_ptr<CANTalon> motor;

public:
	AgitatorSub();
	void InitDefaultCommand();
	void startAgitator();
	void stopAgitator();
	void enableSpeedController();
};

#endif  // AgitatorSub_H
