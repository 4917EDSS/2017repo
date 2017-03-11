#include "SpinUpCmd.h"

SpinUpCmd::SpinUpCmd(float speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	this->speed = speed;
	Requires(shooterSub.get());
}

// Called just before this Command runs the first time
void SpinUpCmd::Initialize() {
	shooterSub->enableShooter();
	shooterSub->setShooterSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void SpinUpCmd::Execute() {
	shooterSub->update(false);
}

// Make this return true when this Command no longer needs to run execute()
bool SpinUpCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SpinUpCmd::End() {
	shooterSub->disableShooter();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUpCmd::Interrupted() {
	End();
}
