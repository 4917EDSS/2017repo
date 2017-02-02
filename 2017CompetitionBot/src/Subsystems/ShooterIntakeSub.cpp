#include "ShooterIntakeSub.h"
#include "../RobotMap.h"

ShooterIntakeSub::ShooterIntakeSub() : Subsystem("ShooterIntakeSub") {
	targetpower = 50;
	motor.reset(new CANTalon(INTAKE_SHOOTER_MOTOR_CANID));
	motor->Set(0);
}

void ShooterIntakeSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ShooterIntakeSub::setIntakeSpeed(){
	motor->Set(targetpower);
}

void ShooterIntakeSub::disableIntake(){
	 motor->Set(0.0);
 }

void ShooterIntakeSub::enableSpeedController(){
 	motor->SetControlMode(frc::CANSpeedController::kPercentVbus);
}
