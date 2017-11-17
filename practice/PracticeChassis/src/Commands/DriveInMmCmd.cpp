#include "DriveInMmCmd.h"

DriveInMmCmd::DriveInMmCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveInMmCmd::Initialize() {
	drivetrainSub->drive(0.3, 0.3);
}

// Called repeatedly when this Command is scheduled to run
void DriveInMmCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveInMmCmd::IsFinished() {
	if(drivetrainSub->getEncoderValue(0) >= 1000.0) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveInMmCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInMmCmd::Interrupted() {

}
