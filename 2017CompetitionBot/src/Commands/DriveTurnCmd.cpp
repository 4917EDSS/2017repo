#include "DriveTurnCmd.h"

DriveTurnCmd::DriveTurnCmd(int angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	targetAngle = angle;
}

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveTurnCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted() {

}
