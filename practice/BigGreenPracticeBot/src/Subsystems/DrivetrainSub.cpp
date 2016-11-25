#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor.reset(new CANTalon(LEFT_DRIVE_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_DRIVE_MOTOR_CANID));
	leftMotorEncoder.reset(new Encoder(LEFT_DRIVE_MOTOR_ENCODER1_DIO, LEFT_DRIVE_MOTOR_ENCODER2_DIO));
	rightMotorEncoder.reset(new Encoder(RIGHT_DRIVE_MOTOR_ENCODER1_DIO, LEFT_DRIVE_MOTOR_ENCODER2_DIO));
	driveShifter.reset(new Solenoid(DRIVE_SHIFTER_SOLENOID_PCM_CHAN));

	// Make the hardware available to be controlled in Test mode
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "leftMotor", leftMotor.get());
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "rightMotor", rightMotor.get());
	LiveWindow::GetInstance()->AddSensor("Drivetrain", "leftMotorEncoder", leftMotorEncoder.get());
	LiveWindow::GetInstance()->AddSensor("Drivetrain", "rightMotorEncoder", rightMotorEncoder.get());
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "driveShifter", driveShifter.get());

	// Initialize hardware that needs to start in a specific state
	driveShifter->Set(true);
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::SetDriveSpeed(float leftSpeed, float rightSpeed)
{
	leftMotor->Set(leftSpeed);
	rightMotor->Set(rightSpeed);
}

void DrivetrainSub::SetDriveShifter(bool on)
{
	driveShifter->Set(on);
}

void DrivetrainSub::ToggleDriveShifter()
{
	driveShifter->Set(!driveShifter->Get());
}
