#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoystickCmd.h"

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

	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Drivetrain L", "Left Motor 1", leftMotor1);
	lw->AddActuator("Drivetrain L", "Left Motor 2", leftMotor2);
	lw->AddActuator("Drivetrain L", "Left Motor 3", leftMotor3);
	lw->AddActuator("Drivetrain R", "Right Motor 1", rightMotor1);
	lw->AddActuator("Drivetrain R", "Right Motor 2", rightMotor2);
	lw->AddActuator("Drivetrain R", "Right Motor 3", rightMotor3);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::drive(double lSpeed, double rSpeed)
{
//	std::cout << "Setting speed to " << lSpeed << ", " << rSpeed;

	leftMotor1->Set(-lSpeed);
	leftMotor2->Set(-lSpeed);
	leftMotor3->Set(-lSpeed);

	rightMotor1->Set(rSpeed);
	rightMotor2->Set(rSpeed);
	rightMotor3->Set(rSpeed);

//	std::cout << " LM1 @ " << leftMotor1->Get() << " RM1 @ " << rightMotor1->Get() << std::endl;
}
