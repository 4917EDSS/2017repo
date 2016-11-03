#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor.reset(new Talon(LEFT_MOTOR_PORT));
	rightMotor.reset(new Talon(RIGHT_MOTOR_PORT));

}

void DrivetrainSub::driveForward()
{
	leftMotor->Set(1.0);
	rightMotor->Set(1.0);
}

void DrivetrainSub::driveBackwards()
{
	leftMotor->Set(-1.0);
	rightMotor->Set(-1.0);
}

void DrivetrainSub::driveStop()
{
	leftMotor->Set(0);
	rightMotor->Set(0);
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
