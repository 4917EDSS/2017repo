#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor.reset( new CANTalon(LEFT_MOTOR_CANID));
	rightMotor.reset( new CANTalon (RIGHT_MOTOR_CANID));

}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSub::drive(float rSpeed, float lSpeed )
{
	leftMotor->Set(lSpeed);
	rightMotor->Set(rSpeed);
}
