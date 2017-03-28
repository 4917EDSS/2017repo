#include "SetIntakeCmd.h"

SetIntakeCmd::SetIntakeCmd(bool newVal) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	intake = newVal;
}

// Called just before this Command runs the first time
void SetIntakeCmd::Initialize() {
	intakeSub -> setIntakeWhenMoving(intake);
}

// Called repeatedly when this Command is scheduled to run
void SetIntakeCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakeCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetIntakeCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntakeCmd::Interrupted() {
	End();
}
