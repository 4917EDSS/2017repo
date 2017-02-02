#include "ShootWhileHeldCmd.h"

ShootWhileHeldCmd::ShootWhileHeldCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
	Requires(shooterIntakeSub.get());
	Requires(agitatorSub.get());
}

// Called just before this Command runs the first time
void ShootWhileHeldCmd::Initialize() {
	shooterSub->enableSpeedController();
	shooterIntakeSub->enableSpeedController();
	agitatorSub->enableSpeedController();
}

// Called repeatedly when this Command is scheduled to run
void ShootWhileHeldCmd::Execute() {
	shooterSub->setSpeed();
	shooterIntakeSub->setIntakeSpeed();
	agitatorSub->startAgitator();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootWhileHeldCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootWhileHeldCmd::End() {
	shooterSub->disableSpeedController();
	shooterSub->disableShooter();
	shooterIntakeSub->disableIntake();
	agitatorSub->stopAgitator();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootWhileHeldCmd::Interrupted() {
	End();
}
