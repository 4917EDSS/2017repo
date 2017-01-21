#include "IncreaseSpeedCmd.h"

IncreaseSpeedCmd::IncreaseSpeedCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IncreaseSpeedCmd::Initialize() {
	shooterSub->increaseSpeed();
}

// Called repeatedly when this Command is scheduled to run
void IncreaseSpeedCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IncreaseSpeedCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IncreaseSpeedCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncreaseSpeedCmd::Interrupted() {

}
