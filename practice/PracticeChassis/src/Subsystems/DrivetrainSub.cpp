#include <WPILib.h>
#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoystickCmd.h"

// Drivetrain values
constexpr float DRIVETRAIN_DIS_PER_PULSE_LEFT = 5000.0/6550.0;
constexpr float DRIVETRAIN_DIS_PER_PULSE_RIGHT = 5000.0/6600.0;
constexpr int ENCODER_CONVERSION_FACTOR = 4;

DrivetrainSub::DrivetrainSub() : Subsystem("DrivetrainSub") {

}

void DrivetrainSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveWithJoystickCmd());
}

void DrivetrainSub::initHardware() {
	leftMotor1.reset(new CANTalon(LEFT_MOTOR1_CANID));
	leftMotor2.reset(new CANTalon(LEFT_MOTOR2_CANID));
	leftMotor3.reset(new CANTalon(LEFT_MOTOR3_CANID));
	rightMotor1.reset(new CANTalon(RIGHT_MOTOR1_CANID));
	rightMotor2.reset(new CANTalon(RIGHT_MOTOR2_CANID));
	rightMotor3.reset(new CANTalon(RIGHT_MOTOR3_CANID));
	leftMotorEnc.reset(new frc::Encoder(LEFT_MOTOR_ENC1_DIO, LEFT_MOTOR_ENC2_DIO));
	rightMotorEnc.reset(new frc::Encoder(RIGHT_MOTOR_ENC1_DIO, RIGHT_MOTOR_ENC2_DIO));
	leftMotorEnc->SetDistancePerPulse(DRIVETRAIN_DIS_PER_PULSE_LEFT*ENCODER_CONVERSION_FACTOR);
	rightMotorEnc->SetDistancePerPulse(DRIVETRAIN_DIS_PER_PULSE_RIGHT*ENCODER_CONVERSION_FACTOR);

	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Drivetrain L", "Left Motor 1", leftMotor1);
	lw->AddActuator("Drivetrain L", "Left Motor 2", leftMotor2);
	lw->AddActuator("Drivetrain L", "Left Motor 3", leftMotor3);
	lw->AddSensor("Drivetrain L", "Encoder", leftMotorEnc);
	lw->AddActuator("Drivetrain R", "Right Motor 1", rightMotor1);
	lw->AddActuator("Drivetrain R", "Right Motor 2", rightMotor2);
	lw->AddActuator("Drivetrain R", "Right Motor 3", rightMotor3);
	lw->AddSensor("Drivetrain R", "Encoder", rightMotorEnc);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::drive(double lSpeed, double rSpeed)
{
	CommandBase::logger->send(CommandBase::logger->DRIVETRAIN, "DT: drive %1.3f, %1.3f\n", lSpeed, rSpeed);
	leftMotor1->Set(-lSpeed);
	leftMotor2->Set(-lSpeed);
	leftMotor3->Set(-lSpeed);

	rightMotor1->Set(rSpeed);
	rightMotor2->Set(rSpeed);
	rightMotor3->Set(rSpeed);
}

double DrivetrainSub::getEncoderValue(int encoderId)
{
	double value = 0.0;

	switch(encoderId)
	{
	case 0:
		value = leftMotorEnc->GetDistance();
		break;
	case 1:
		value = rightMotorEnc->GetDistance();
		break;
	default:
		CommandBase::logger->send(CommandBase::logger->ASSERTS, "DrivetrainSub::getEncoderValue: Invalid encoder ID %d", encoderId);
		break;
	}

	return value;
}
