#include <Commands/ShootCmd.h>

ShootCmd::ShootCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
	//Requires(agitatorSub.get());
}

// Called just before this Command runs the first time
void ShootCmd::Initialize() {
	shooterSub->enableShooter();
	//agitatorSub->enableSpeedController();
}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() {
	shooterSub->update();
	//agitatorSub->startAgitator();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootCmd::End() {
	shooterSub->disableShooter();
	//agitatorSub->stopAgitator();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootCmd::Interrupted() {
	End();
}
