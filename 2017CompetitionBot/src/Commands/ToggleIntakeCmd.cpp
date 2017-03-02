#include "ToggleIntakeCmd.h"

ToggleIntakeCmd::ToggleIntakeCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleIntakeCmd::Initialize() {
	intakeSub -> toggleIntake();
}

// Called repeatedly when this Command is scheduled to run
void ToggleIntakeCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleIntakeCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleIntakeCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleIntakeCmd::Interrupted() {

}
