#include <Commands/AutoBoilerGearGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "DriveStraightCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"

AutoBoilerGearGrp::AutoBoilerGearGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to boiler gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2360}, std::vector<double> {0, 700, 1550},
									std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1450}, std::vector<double> {0, 600, 1450},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));

}
