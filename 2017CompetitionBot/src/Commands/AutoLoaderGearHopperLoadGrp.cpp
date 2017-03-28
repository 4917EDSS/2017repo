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

	//Drive to hopper gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230},
									std::vector<double> {0, 700, 2360}, std::vector<double> {0, 700, 1550}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475},
									std::vector<double> {0, 600, 1450}, std::vector<double> {0, 600, 1450}));

	AddSequential(new WaitCommand(GEAR_WAIT_TIME * 3));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -2700, -2900, -3800}, std::vector<double> {0, -200, -2000, -2500, -3100},
									std::vector<double> {0, -200, -2000, -2500, -3100}, std::vector<double> {0, -1000, -2700, -2900, -3800}));

	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -550}, std::vector<double> {0, -75, -400},
									std::vector<double> {0, -75, -400}, std::vector<double> {0, -75, -550}));

	AddParallel(new SetHopperOpenCmd(false));
}
