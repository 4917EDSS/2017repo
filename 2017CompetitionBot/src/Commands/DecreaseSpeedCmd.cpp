#include "DecreaseSpeedCmd.h"

DecreaseSpeedCmd::DecreaseSpeedCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DecreaseSpeedCmd::Initialize() {
	shooterSub->decreaseSpeed();
}

// Called repeatedly when this Command is scheduled to run
void DecreaseSpeedCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DecreaseSpeedCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DecreaseSpeedCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecreaseSpeedCmd::Interrupted() {

}
