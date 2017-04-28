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
	lastMoveTime = 0;
}

// Called repeatedly when this Command is scheduled to run
void SilkyRotateCmd::Execute() {
	// TODO:  Compensate for Yaw going negative at the 179/-180 point
	double power = srm.execute(drivetrainSub->getYaw());
	drivetrainSub->drive(power, -power);
}

#define MAX(a, b) ((a)<(b)?(b):(a))

// Make this return true when this Command no longer needs to run execute()
bool SilkyRotateCmd::IsFinished() {

	double maxSpeed = MAX(fabs(drivetrainSub->getLeftEncoderSpeed()), fabs(drivetrainSub->getRightEncoderSpeed()));
	// TODO:  Compensate for Yaw going negative at the 179/-180 point
	if(fabs(maxSpeed) < 40){
		timeFromLastMove = TimeSinceInitialized() - lastMoveTime;
	}
	else{
		lastMoveTime = TimeSinceInitialized();
	}
	if((srm.isFinished(drivetrainSub->getYaw(), maxSpeed)) or (timeFromLastMove > 1)) {
		std::cout << "Velocity: " << maxSpeed << std::endl;
		std::cout << "Yaw: " << drivetrainSub->getYaw() << std::endl;
	}
	return ((srm.isFinished(drivetrainSub->getYaw(), maxSpeed)) or (timeFromLastMove > 1));
}

// Called once after isFinished returns true
void SilkyRotateCmd::End() {
	drivetrainSub->drive(0,0);
	drivetrainSub->resetAHRS();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SilkyRotateCmd::Interrupted() {
	End();
}
