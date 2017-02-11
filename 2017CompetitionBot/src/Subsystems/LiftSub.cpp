#include "LiftSub.h"
#include "../RobotMap.h"

LiftSub::LiftSub() : Subsystem("ExampleSubsystem") {
	liftMotor.reset(new CANTalon(LIFT_MOTOR_CANID));
}

void LiftSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftSub::SetLiftMotor(float speed){

	liftMotor->Set(-speed);
}
