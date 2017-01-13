#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DrivetrainSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> leftMotor;
	std::unique_ptr<CANTalon> rightMotor;
	std::unique_ptr<CANTalon> left2Motor;
	std::unique_ptr<CANTalon> right2Motor;
	std::unique_ptr<Encoder> leftMotorEncoder;
	std::unique_ptr<Encoder> rightMotorEncoder;
	std::unique_ptr<Solenoid> driveShifter;	// Not present on Big Green but needed for the practice board
public:
	DrivetrainSub();
	void InitDefaultCommand();
	void SetDriveSpeed(float leftMotor, float rightMotor);
	void SetDriveShifter(bool on);
	void ToggleDriveShifter(void);
};

#endif
