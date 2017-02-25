#ifndef IntakeSub_H
#define IntakeSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"

class IntakeSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> pickupMotor;
	std::shared_ptr<frc::DoubleSolenoid> gearFlaps;

public:
	IntakeSub();
	void InitDefaultCommand();
	void setPickupMotor(double speed);
	void openGearFlaps();
	void closeGearFlaps();
};

#endif  // IntakeSub_H
