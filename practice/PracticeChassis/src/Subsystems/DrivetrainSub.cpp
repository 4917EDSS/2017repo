#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub() : Subsystem("DrivetrainSub") {
	leftMotor1.reset(new CANTalon(LEFT_MOTOR1_CANID));
	leftMotor2.reset(new CANTalon(LEFT_MOTOR2_CANID));
	rightMotor1.reset(new CANTalon(RIGHT_MOTOR1_CANID));
	rightMotor2.reset(new CANTalon(RIGHT_MOTOR2_CANID));

}

void DrivetrainSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::drive(double rSpeed, double lSpeed)
{
	leftMotor1->Set(lSpeed);
	leftMotor2->Set(lSpeed);
	rightMotor1->Set(rSpeed);
	rightMotor2->Set(rSpeed);
}
