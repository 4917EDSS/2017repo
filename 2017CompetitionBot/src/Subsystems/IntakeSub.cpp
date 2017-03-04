#include "IntakeSub.h"
#include "../RobotMap.h"
#include "Commands/RunPickupCmd.h"

IntakeSub::IntakeSub() : Subsystem("IntakeSub") {
	pickupMotor.reset(new CANTalon(INTAKE_MOTOR_CANID));
	gearFlaps.reset(new frc::DoubleSolenoid(GEARFLAPS_PCM_ID1, GEARFLAPS_PCM_ID2));
	intakeWhenMoving = true;
}

void IntakeSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new RunPickupCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void IntakeSub::setPickupMotor(double speed) {
	pickupMotor->Set(speed);
}

void IntakeSub::openGearFlaps() {
	gearFlaps->Set(frc::DoubleSolenoid::Value::kForward);
}

void IntakeSub::closeGearFlaps() {
	gearFlaps->Set(frc::DoubleSolenoid::Value::kReverse);
}

void IntakeSub::toggleIntake() {
	intakeWhenMoving = !intakeWhenMoving;
}

bool IntakeSub::getIntakeWhenMoving() {
	return intakeWhenMoving;
}
