#include "IntakeSub.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub() : Subsystem("IntakeSub") {
	pickupMotor.reset(new CANTalon(INTAKE_MOTOR_CANID));
	gearFlaps.reset(new frc::DoubleSolenoid(GEARFLAPS_PCM_ID1, GEARFLAPS_PCM_ID2));
}

void IntakeSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void IntakeSub::setPickupMotor(double speed) {
	pickupMotor->Set(speed);
}

void IntakeSub::openGearFlaps() {
	gearFlaps->Set(frc::DoubleSolenoid::Value::kReverse);
}

void IntakeSub::closeGearFlaps() {
	gearFlaps->Set(frc::DoubleSolenoid::Value::kForward);
}
