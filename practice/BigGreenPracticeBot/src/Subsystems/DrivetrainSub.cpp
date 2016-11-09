#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor.reset(new CANTalon(LEFT_DRIVE_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_DRIVE_MOTOR_CANID));
	leftMotorEncoder.reset(new Encoder(LEFT_DRIVE_MOTOR_ENCODER1_DIO, LEFT_DRIVE_MOTOR_ENCODER2_DIO));
	rightMotorEncoder.reset(new Encoder(RIGHT_DRIVE_MOTOR_ENCODER1_DIO, LEFT_DRIVE_MOTOR_ENCODER2_DIO));
	driveShifter.reset(new DoubleSolenoid(DRIVE_SHIFTER_DBLSOLENOID1_PCM_CHAN, DRIVE_SHIFTER_DBLSOLENOID2_PCM_CHAN));
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
