#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{

}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	leftMotor.reset(new CANTalon(LEFT_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_MOTOR_CANID));

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
