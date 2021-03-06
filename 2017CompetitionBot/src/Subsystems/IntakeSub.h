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
	bool intakeWhenMoving;

public:
	IntakeSub();
	void InitDefaultCommand();
	void setPickupMotor(double speed);
	void openGearFlaps();
	void closeGearFlaps();
	void toggleIntake();
	bool getIntakeWhenMoving();
	void setIntakeWhenMoving(bool newVal);
};

#endif  // IntakeSub_H
