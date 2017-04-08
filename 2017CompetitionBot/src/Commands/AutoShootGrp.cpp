#include "AutoShootGrp.h"
#include "SilkyDriveCmd.h"
#include <vector>
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"
#include "Commands/HopperPulseCmd.h"

AutoShootGrp::AutoShootGrp() {
	//Pulse Hopper
	AddParallel(new HopperPulseCmd(TEN_BALL_SHOT_TIME));
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, TEN_BALL_SHOT_TIME));

	//Reverse turn
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000,-3900},std::vector<double> {0,-300,-1200}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 200, 1700},std::vector<double> {0, 200, 1700}));
}
