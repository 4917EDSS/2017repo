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
	std::shared_ptr<frc::Encoder> motorEnc;


public:
	ShooterSub();
	void InitDefaultCommand();
	void setShooterSpeed(double speed);
	int getEncoder();
	void resetEncoder();
	double getSpeed();
};

#endif  // ShooterSub_H
