#include "SwitchCamerasCmd.h"

SwitchCamerasCmd::SwitchCamerasCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveVisionSub.get());
}

// Called just before this Command runs the first time
void SwitchCamerasCmd::Initialize() {
	driveVisionSub->switchCam();
}

// Called repeatedly when this Command is scheduled to run
void SwitchCamerasCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SwitchCamerasCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SwitchCamerasCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchCamerasCmd::Interrupted() {

}
