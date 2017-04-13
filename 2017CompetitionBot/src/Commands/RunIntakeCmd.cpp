#include "RunIntakeCmd.h"
#include "Subsystems/IntakeSub.h"

RunIntakeCmd::RunIntakeCmd(double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intakeSub.get());
	this->speed = speed;
}

// Called just before this Command runs the first time
void RunIntakeCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunIntakeCmd::Execute() {
	intakeSub->setPickupMotor(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunIntakeCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunIntakeCmd::End() {
	intakeSub->setPickupMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunIntakeCmd::Interrupted() {
	End();
}
