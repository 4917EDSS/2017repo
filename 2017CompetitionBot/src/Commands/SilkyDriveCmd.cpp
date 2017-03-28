#include "SilkyDriveCmd.h"

SilkyDriveCmd::SilkyDriveCmd(std::vector<double> leftPositions, std::vector<double> rightPositions)
 : smm(leftPositions, rightPositions, MAX_ACCEL, MAX_DECEL, MAX_VEL, STOPPING_DISTANCE_TOLERANCE, STOPPING_SPEED_TOLERANCE) {
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrainSub.get());
}

SilkyDriveCmd::SilkyDriveCmd(std::vector<double> leftPostionsBlue, std::vector<double> rightPostitionsBlue, std::vector<double> leftPositionsRed, std::vector<double> rightPositionsRed) {

}

// Called just before this Command runs the first time
void SilkyDriveCmd::Initialize() {
	smm.setKvKaKpKd(SILKY_KV, SILKY_KA, SILKY_KP, SILKY_KD);
	smm.reset();
	//smm.setAlliance(frc::DriverStation::Alliance::kRed);
	smm.setAlliance(frc::DriverStation::GetInstance().GetAlliance());
	drivetrainSub->reset();
}

// Called repeatedly when this Command is scheduled to run
void SilkyDriveCmd::Execute() {
	std::pair<double, double> speed = smm.execute(drivetrainSub->getLeftEncoder(), drivetrainSub->getRightEncoder());
	drivetrainSub->drive(speed.first, speed.second);
}

// Make this return true when this Command no longer needs to run execute()
bool SilkyDriveCmd::IsFinished() {
	return smm.isFinished(drivetrainSub->getLeftEncoder(), drivetrainSub->getLeftEncoderSpeed(), drivetrainSub->getRightEncoder(), drivetrainSub->getRightEncoderSpeed());
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
