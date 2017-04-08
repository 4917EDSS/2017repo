#include "SilkyDriveCmd.h"

SilkyDriveCmd::SilkyDriveCmd(std::vector<double> leftPositions, std::vector<double> rightPositions)
 : smmBlue(leftPositions, rightPositions, MAX_ACCEL, MAX_DECEL, MAX_VEL, STOPPING_DISTANCE_TOLERANCE, STOPPING_SPEED_TOLERANCE),
   smmRed(rightPositions, leftPositions, MAX_ACCEL, MAX_DECEL, MAX_VEL, STOPPING_DISTANCE_TOLERANCE, STOPPING_SPEED_TOLERANCE){
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrainSub.get());
}

SilkyDriveCmd::SilkyDriveCmd(std::vector<double> leftPositionsBlue, std::vector<double> rightPositionsBlue, std::vector<double> leftPositionsRed, std::vector<double> rightPositionsRed) :
		smmBlue(leftPositionsBlue, rightPositionsBlue, MAX_ACCEL, MAX_DECEL, MAX_VEL, STOPPING_DISTANCE_TOLERANCE, STOPPING_SPEED_TOLERANCE),
		smmRed(leftPositionsRed, rightPositionsRed, MAX_ACCEL, MAX_DECEL, MAX_VEL, STOPPING_DISTANCE_TOLERANCE, STOPPING_SPEED_TOLERANCE){
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void SilkyDriveCmd::Initialize() {
	if(frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue) {
		smm = &smmBlue;
	} else {
		smm = &smmRed;
	}
	smm->setKvKaKpKd(SILKY_KV, SILKY_KA, SILKY_KP, SILKY_KD);
	smm->reset();
	drivetrainSub->reset();
	timeFromLastMove = 0;
	lastMoveTime = 0;
}

// Called repeatedly when this Command is scheduled to run
void SilkyDriveCmd::Execute() {
	std::pair<double, double> speed = smm->execute(drivetrainSub->getLeftEncoder(), drivetrainSub->getRightEncoder());
	drivetrainSub->drive(speed.first, speed.second);
}

// Make this return true when this Command no longer needs to run execute()
bool SilkyDriveCmd::IsFinished() {
	if(fabs(drivetrainSub->getLeftEncoderSpeed()) < 40 and fabs(drivetrainSub->getRightEncoderSpeed()) < 40){
		timeFromLastMove = TimeSinceInitialized() - lastMoveTime;
	}
	else{
		lastMoveTime = TimeSinceInitialized();
	}
	return ((smm->isFinished(drivetrainSub->getLeftEncoder(), drivetrainSub->getLeftEncoderSpeed(), drivetrainSub->getRightEncoder(), drivetrainSub->getRightEncoderSpeed())) or (timeFromLastMove > 1));
}

// Called once after isFinished returns true
void SilkyDriveCmd::End() {
	drivetrainSub->drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SilkyDriveCmd::Interrupted() {
	End();
}
