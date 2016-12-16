#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
public:
	enum ShiftState {
		HIGH, LOW
	};
	DrivetrainSub();
	void InitDefaultCommand();
	void drive(float oneSpeed, float twoSpeed);
	void shift(ShiftState gear);
	ShiftState getGear();
	double getDriveRate();

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> motor1;
	std::unique_ptr<CANTalon> motor2;
	std::unique_ptr<Encoder> motorEnc1;
	std::unique_ptr<Encoder> motorEnc2;
	std::unique_ptr<DoubleSolenoid> shifter;

};

#endif
