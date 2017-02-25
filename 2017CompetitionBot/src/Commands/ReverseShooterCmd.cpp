#include "ReverseShooterCmd.h"

ReverseShooterCmd::ReverseShooterCmd(float newSpeed) {
	Requires(shooterSub.get());
	speed = newSpeed;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ReverseShooterCmd::Initialize() {
	shooterSub->setShooterSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void ReverseShooterCmd::Execute() {
	shooterSub->update();
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseShooterCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ReverseShooterCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseShooterCmd::Interrupted() {

}
