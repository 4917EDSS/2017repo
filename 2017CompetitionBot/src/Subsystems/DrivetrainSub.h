#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class DrivetrainSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> leftMotor;
	std::shared_ptr<CANTalon> rightMotor;

public:
	DrivetrainSub();
	void InitDefaultCommand();
	void drive( double lSpeed, double rSpeed );
};

#endif  // DrivetrainSub_H
