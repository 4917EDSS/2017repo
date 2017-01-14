#include "LiftCmd.h"

LiftCmd::LiftCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(liftSub.get());
}

// Called just before this Command runs the first time
void LiftCmd::Initialize() {
	liftSub->SetLiftMotor(1.0);
}

// Called repeatedly when this Command is scheduled to run
void LiftCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftCmd::End() {
	liftSub->SetLiftMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftCmd::Interrupted() {
	End();
}
