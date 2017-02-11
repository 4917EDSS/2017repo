#include "AgitatorSub.h"
#include "../RobotMap.h"

AgitatorSub::AgitatorSub() : Subsystem("AgitatorSub") {
	//motor.reset(new CANTalon(AGITATOR_MOTOR_CANID));
	//motor->Set(0);
}

void AgitatorSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void AgitatorSub::startAgitator(){
	//motor->Set(power);
}

void AgitatorSub::stopAgitator(){
	//motor->Set(0.0);
}

void AgitatorSub::enableSpeedController(){
 	//motor->SetControlMode(frc::CANSpeedController::kPercentVbus);
}
