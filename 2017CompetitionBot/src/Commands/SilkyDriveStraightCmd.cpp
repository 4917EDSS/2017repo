#include "SilkyDriveStraightCmd.h"

SilkyDriveStraightCmd::SilkyDriveStraightCmd(float targetDis): smm(targetDis, 2.92, 4.9, 1.0, -0.2, 0, 0) {
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void SilkyDriveStraightCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SilkyDriveStraightCmd::Execute() {
	float speed = smm.execute(0);
	drivetrainSub->drive(speed, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool SilkyDriveStraightCmd::IsFinished() {
	return smm.isFinished();
}

// Called once after isFinished returns true
void SilkyDriveStraightCmd::End() {
	drivetrainSub->drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SilkyDriveStraightCmd::Interrupted() {
	End();
}
