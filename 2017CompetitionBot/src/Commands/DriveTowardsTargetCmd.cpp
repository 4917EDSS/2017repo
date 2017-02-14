#include "DriveTowardsTargetCmd.h"

DriveTowardsTargetCmd::DriveTowardsTargetCmd(double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
	driveSpeed = speed;
}

// Called just before this Command runs the first time
void DriveTowardsTargetCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveTowardsTargetCmd::Execute() {
	drivetrainSub->Update(driveSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTowardsTargetCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveTowardsTargetCmd::End() {
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTowardsTargetCmd::Interrupted() {
	End();
}
