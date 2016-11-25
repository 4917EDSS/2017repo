#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
void drive(float rSpeed, float rSpeed);
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std:: unique_ptr<CANTalon> 1leftmotor1;
	std:: unique_ptr<CANTalon> 1rightmotor1;
public:
	DrivetrainSub();
	void InitDefaultCommand();
};

#endif
