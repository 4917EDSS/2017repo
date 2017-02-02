#ifndef ShooterIntakeSub_H
#define ShooterIntakeSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"

class ShooterIntakeSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> motor;
	double targetpower;

public:
	ShooterIntakeSub();
	void InitDefaultCommand();
	void setIntakeSpeed();
	void disableIntake();
	void enableSpeedController();
};

#endif  // ShooterIntakeSub_H
