#include "ToggleTalonCmd.h"

ToggleTalonCmd::ToggleTalonCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intakeSub.get());
}

// Called just before this Command runs the first time
void ToggleTalonCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleTalonCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleTalonCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleTalonCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleTalonCmd::Interrupted() {

}
