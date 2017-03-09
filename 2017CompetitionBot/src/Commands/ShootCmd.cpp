#include <Commands/ShootCmd.h>

ShootCmd::ShootCmd(float speed) : speed(speed), time(0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooterSub.get());
	Requires(intakeSub.get());
	shouldStopAtTime = false;
}

ShootCmd::ShootCmd(float speed, float time) : speed(speed), time(time) {
	Requires(shooterSub.get());
	Requires(intakeSub.get());
	shouldStopAtTime = true;
}

// Called just before this Command runs the first time
void ShootCmd::Initialize() {
	shooterSub->enableShooter();
	intakeSub->setPickupMotor(1.0);
	shooterSub->setShooterSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() {
	shooterSub->update();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootCmd::IsFinished() {
	if (shouldStopAtTime){
		return TimeSinceInitialized() > time;
	}
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
