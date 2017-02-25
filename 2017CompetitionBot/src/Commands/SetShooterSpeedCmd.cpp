#include "SetShooterSpeedCmd.h"

SetShooterSpeedCmd::SetShooterSpeedCmd(float speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	shooterSpeed = speed;
}

// Called just before this Command runs the first time
void SetShooterSpeedCmd::Initialize() {
	shooterSub->setShooterSpeed(shooterSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SetShooterSpeedCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterSpeedCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetShooterSpeedCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterSpeedCmd::Interrupted() {

}
