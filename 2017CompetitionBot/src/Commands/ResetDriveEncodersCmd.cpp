#include "ResetDriveEncodersCmd.h"

ResetDriveEncodersCmd::ResetDriveEncodersCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void ResetDriveEncodersCmd::Initialize() {
	drivetrainSub->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void ResetDriveEncodersCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ResetDriveEncodersCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetDriveEncodersCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDriveEncodersCmd::Interrupted() {

}
