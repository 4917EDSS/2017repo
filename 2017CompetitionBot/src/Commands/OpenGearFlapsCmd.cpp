#include "OpenGearFlapsCmd.h"

OpenGearFlapsCmd::OpenGearFlapsCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intakeSub.get());
}

// Called just before this Command runs the first time
void OpenGearFlapsCmd::Initialize() {
	intakeSub->openGearFlaps();
}

// Called repeatedly when this Command is scheduled to run
void OpenGearFlapsCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OpenGearFlapsCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OpenGearFlapsCmd::End() {
	intakeSub->closeGearFlaps();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenGearFlapsCmd::Interrupted() {
	End();
}