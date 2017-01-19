#include "SetShooterSpeedCmd.h"


SetShooterSpeedCmd::SetShooterSpeedCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
}

// Called just before this Command runs the first time
void SetShooterSpeedCmd::Initialize() {
	Preferences *prefs = Preferences::GetInstance();
	targetSpeed = prefs->GetDouble("SetShooterSpeed", 0.0);
	shooterSub->setShooterSpeed(targetSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SetShooterSpeedCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterSpeedCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetShooterSpeedCmd::End() {
	shooterSub->setShooterSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterSpeedCmd::Interrupted() {
	End();
}
