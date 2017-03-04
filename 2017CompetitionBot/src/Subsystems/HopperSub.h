#ifndef HopperSub_H
#define HopperSub_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class HopperSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<frc::DoubleSolenoid> hopper;

public:
	HopperSub();
	void InitDefaultCommand();
	void expandHopper();
	void shrinkHopper();
};

#endif  // HopperSub_H
