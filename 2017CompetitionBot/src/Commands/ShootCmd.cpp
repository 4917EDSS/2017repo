#include <Commands/ShootCmd.h>

ShootCmd::ShootCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
	Requires(intakeSub.get());
	shouldSetSpeed = false;
}

ShootCmd::ShootCmd(float speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
	Requires(intakeSub.get());
	this->speed = speed;
	shouldSetSpeed = true;
}

// Called just before this Command runs the first time
void ShootCmd::Initialize() {
	shooterSub->enableShooter();
	intakeSub->setPickupMotor(1.0);
	if(shouldSetSpeed){
		shooterSub->setShooterSpeed(speed);
	}
}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() {
	shooterSub->update();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootCmd::End() {
	shooterSub->disableShooter();
	intakeSub->setPickupMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootCmd::Interrupted() {
	End();
}
