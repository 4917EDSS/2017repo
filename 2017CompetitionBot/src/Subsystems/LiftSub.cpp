#include "LiftSub.h"
#include "../RobotMap.h"

LiftSub::LiftSub() : Subsystem("ExampleSubsystem") {
	liftMotor.reset(new CANTalon(LIFT_MOTOR_CANID));
	liftMotor2.reset(new CANTalon(LIFT_MOTOR2_CANID));

	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Lift", "Lift Motor 1", liftMotor);
	lw->AddActuator("Lift", "Lift Motor 2", liftMotor2);
}

void LiftSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftSub::SetLiftMotor(float speed){

	liftMotor->Set(-speed);
	liftMotor2->Set(-speed);
}
