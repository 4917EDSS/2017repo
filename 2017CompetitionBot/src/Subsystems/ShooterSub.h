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

	std::shared_ptr<CANTalon> shooterMotor1;
	std::shared_ptr<CANTalon> shooterMotor2;
	std::shared_ptr<CANTalon> feederMotor1;
	std::shared_ptr<CANTalon> feederMotor2;
	double targetSpeed;
	double adjustmentSpeed;

public:
	ShooterSub();
	void InitDefaultCommand();

	// primary interface
	void update(bool shooting);
	void enableShooter();
	void disableShooter();

	// support functions
	void increaseSpeed();
	void decreaseSpeed();
	int getEncoder();
	void resetEncoder();
	double getSpeed();
	double getTargetSpeed();
	double getFeederSpeed();
	void enableSpeedController();
	void disableSpeedController();
	void setFeederSpeed(float speed);
	void setShooterSpeed(float newSpeed);
	void setFeeder1(float speed);
};

#endif  // ShooterSub_H
