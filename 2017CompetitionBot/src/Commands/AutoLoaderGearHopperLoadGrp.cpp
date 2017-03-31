#include "AutoLoaderGearHopperLoadGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include "SetHopperOpenCmd.h"
#include "ToggleShifterCmd.h"
#include "ShootCmd.h"
#include <vector>

AutoLoaderGearHopperLoadGrp::AutoLoaderGearHopperLoadGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to loader gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1451}, std::vector<double> {0, 930, 2230},
									std::vector<double> {0, 850, 2510}, std::vector<double> {0, 850, 1700}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1480}, std::vector<double> {0, 600, 1480},
									std::vector<double> {0, 600, 1435}, std::vector<double> {0, 600, 1435}));

	AddSequential(new WaitCommand(GEAR_WAIT_TIME * 3));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -950, -2650, -2850, -3700}, std::vector<double> {0, -150, -1950, -2450, -3000},
									std::vector<double> {0, -200, -2000, -2500, -3100}, std::vector<double> {0, -1000, -2700, -2900, -3800}));

	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -550}, std::vector<double> {0, -75, -400},
									std::vector<double> {0, -75, -400}, std::vector<double> {0, -75, -550}));

	AddParallel(new SetHopperOpenCmd(false));
}
