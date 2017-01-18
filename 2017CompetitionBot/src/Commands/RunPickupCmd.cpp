#include "RunPickupCmd.h"

RunPickupCmd::RunPickupCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intakeSub.get());
}

// Called just before this Command runs the first time
void RunPickupCmd::Initialize() {
	intakeSub->setPickupMotor(0.5);
}

// Called repeatedly when this Command is scheduled to run
void RunPickupCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RunPickupCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunPickupCmd::End() {
	intakeSub->setPickupMotor(0.00);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunPickupCmd::Interrupted() {
	End();
}
