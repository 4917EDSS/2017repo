#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub() : Subsystem("DrivetrainSub") {
	leftMotor.reset(new CANTalon(LEFT_DRIVE_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_DRIVE_MOTOR_CANID));
}

void DrivetrainSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::drive(double lSpeed, double rSpeed)
{
	leftMotor->Set(lSpeed);
	rightMotor->Set(rSpeed);
}
