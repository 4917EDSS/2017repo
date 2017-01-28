#ifndef ShooterSub_H
#define ShooterSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"


class ShooterSub : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Note:  These are declared as shared_ptr (not unique_ptr) because we share them with the
	//        LiveWindow for testing purposes.

	std::shared_ptr<CANTalon> motor;
	double targetSpeed;

public:
	ShooterSub();
	void InitDefaultCommand();
	void setSpeed();
	void disableShooter();
	void increaseSpeed();
	void decreaseSpeed();
	int getEncoder();
	void resetEncoder();
	double getSpeed();
	double getTargetSpeed();
	void enableSpeedController();
	void disableSpeedController();
};

#endif  // ShooterSub_H
