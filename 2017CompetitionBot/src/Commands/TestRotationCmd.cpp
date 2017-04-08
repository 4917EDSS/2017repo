#include "TestRotationCmd.h"

TestRotationCmd::TestRotationCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void TestRotationCmd::Initialize() {
	drivetrainSub->CharaterizeRobotRotation();
}

// Called repeatedly when this Command is scheduled to run
void TestRotationCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TestRotationCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TestRotationCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestRotationCmd::Interrupted() {

}
