#include <Commands/AutoBoilerGearGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"

AutoBoilerGearGrp::AutoBoilerGearGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to boiler gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 875, 2535}, std::vector<double> {0, 875, 1725},
									std::vector<double> {0, 930, 1477}, std::vector<double> {0, 930, 2233}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 450, 1300}, std::vector<double> {0, 450, 1300},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 450, 1300}, std::vector<double> {0, 450, 1300},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1450}, std::vector<double> {0, 600, 1450},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));

}
