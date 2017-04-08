#include "SilkyRotateCmd.h"

SilkyRotateCmd::SilkyRotateCmd(double angle) : srm(angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void SilkyRotateCmd::Initialize() {
	srm.reset();
	drivetrainSub->reset();
	drivetrainSub->resetAHRS();
	timeFromLastMove = 0;
}

// Called repeatedly when this Command is scheduled to run
void SilkyRotateCmd::Execute() {
	// TODO:  Compensate for Yaw going negative at the 179/-180 point
	double power = srm.execute(drivetrainSub->getYaw());
	drivetrainSub->drive(power, -power);
}

// Make this return true when this Command no longer needs to run execute()
bool SilkyRotateCmd::IsFinished() {
	// TODO:  Compensate for Yaw going negative at the 179/-180 point
	if(fabs(drivetrainSub->getLeftEncoderSpeed()) < 40 and fabs(drivetrainSub->getRightEncoderSpeed()) < 40){
		timeFromLastMove = TimeSinceInitialized() - lastMoveTime;
	}
	else{
		lastMoveTime = TimeSinceInitialized();
	}
	return ((srm.isFinished(drivetrainSub->getYaw())) or (timeFromLastMove > 1));
}

// Called once after isFinished returns true
void SilkyRotateCmd::End() {
	drivetrainSub->resetAHRS();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SilkyRotateCmd::Interrupted() {
	End();
}
