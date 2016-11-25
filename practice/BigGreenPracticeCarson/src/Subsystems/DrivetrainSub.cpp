#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	motor1.reset(new CANTalon(MOTOR1_CANID));
	motor2.reset(new CANTalon(MOTOR2_CANID));
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSub::drive(float oneSpeed, float twoSpeed)
{
	motor1->Set(oneSpeed);
	motor2->Set(twoSpeed);
}
