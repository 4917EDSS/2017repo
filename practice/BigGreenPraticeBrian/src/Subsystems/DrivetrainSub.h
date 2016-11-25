#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	std::unique_ptr<CANTalon>leftMotor;
	std::unique_ptr<CANTalon>rightMotor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	void drive(float rSpeed, float lSpeed);
	DrivetrainSub();
	void InitDefaultCommand();
};

#endif
