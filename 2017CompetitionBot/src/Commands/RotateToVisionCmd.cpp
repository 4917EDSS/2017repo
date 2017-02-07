#include "RotateToVisionCmd.h"

RotateToVisionCmd::RotateToVisionCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void RotateToVisionCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RotateToVisionCmd::Execute() {
	if(CommandBase::x<0){
		drivetrainSub->drive(-0.5, 0.5);
	}
	else if(CommandBase::x>0){
		drivetrainSub->drive(0.5, -0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToVisionCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RotateToVisionCmd::End() {
	drivetrainSub->drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToVisionCmd::Interrupted() {
	End();
}
