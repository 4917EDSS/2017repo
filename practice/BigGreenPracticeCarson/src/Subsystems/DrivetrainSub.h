#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> motor1;
	std::unique_ptr<CANTalon> motor2;
public:
	DrivetrainSub();
	void InitDefaultCommand();
	void drive(float oneSpeed, float twoSpeed);
};

#endif
