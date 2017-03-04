#include "HopperSub.h"
#include "../RobotMap.h"

HopperSub::HopperSub() : Subsystem("ExampleSubsystem") {
	hopper.reset(new frc::DoubleSolenoid(HOPPER_PCM_ID1, HOPPER_PCM_ID2));
}

void HopperSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void HopperSub::expandHopper(){
	hopper->Set(frc::DoubleSolenoid::Value::kForward);
}

void HopperSub::shrinkHopper(){
	hopper->Set(frc::DoubleSolenoid::Value::kReverse);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
