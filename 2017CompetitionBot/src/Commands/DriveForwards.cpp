#include "DriveForwards.h"

DriveForwards::DriveForwards() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveForwards::Initialize() {
	accelTime = ((double) GetFPGATime()) / 1000000.0;
	drivetrainSub->drive(0.7, 0.7);
}
#include <iostream>
// Called repeatedly when this Command is scheduled to run
void DriveForwards::Execute() {
	if (drivetrainSub->getLeftEncoderSpeed() > 2800) {
		if (accelTime > 0) {
			std::cout << ((double) GetFPGATime()) / 1000000.0 - accelTime << std::endl;
			accelTime = -1;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwards::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveForwards::End() {
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwards::Interrupted() {
	End();
}
