#include "ReverseShooterCmd.h"

ReverseShooterCmd::ReverseShooterCmd(float newSpeed) {
	Requires(shooterSub.get());
	Requires(intakeSub.get());
	speed = newSpeed;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ReverseShooterCmd::Initialize() {
	shooterSub->setShooterSpeed(speed);
	intakeSub->setPickupMotor(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void ReverseShooterCmd::Execute() {
	shooterSub->update();
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseShooterCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseShooterCmd::End() {
	shooterSub->disableShooter();
	shooterSub->setFeederSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseShooterCmd::Interrupted() {
	End();
}
