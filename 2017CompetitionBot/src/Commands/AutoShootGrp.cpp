#include "AutoShootGrp.h"
#include "SilkyDriveCmd.h"
#include <vector>
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"
#include "Commands/HopperPulseCmd.h"

AutoShootGrp::AutoShootGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Pulse Hopper
	AddParallel(new HopperPulseCmd(TEN_BALL_SHOT_TIME));
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, TEN_BALL_SHOT_TIME));

	//Reverse turn
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000,-3900},std::vector<double> {0,-300,-1200}));
	} else {
		// drive straight
	}
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 200, 1700},std::vector<double> {0, 200, 1700}));
}
