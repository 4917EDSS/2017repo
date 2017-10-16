#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class DrivetrainSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> leftMotor1;
	std::shared_ptr<CANTalon> leftMotor2;
	std::shared_ptr<CANTalon> rightMotor1;
	std::shared_ptr<CANTalon> rightMotor2;

public:
	DrivetrainSub();
	void InitDefaultCommand();
	void drive(double rSpeed, double lSpeed);
};

#endif  // DrivetrainSub_H
