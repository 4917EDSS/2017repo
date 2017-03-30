#include <Commands/AutoBoilerGearShootGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "DriveStraightCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"

AutoBoilerGearShootGrp::AutoBoilerGearShootGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to boiler gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2360}, std::vector<double> {0, 700, 1550},
									//std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230}));
									std::vector<double> {0, 930, 1492}, std::vector<double> {0, 930, 2230}));
									//std::vector<double> {0, 930, 1457}, std::vector<double> {0, 930, 2230}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1450}, std::vector<double> {0, 600, 1450},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));

	//Wait at gear
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -300}, std::vector<double> {0, -200, -2300},
									std::vector<double> {0, -200, -2300}, std::vector<double> {0, -200, -400}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 2300, 2800}, std::vector<double> {0, 1000, 1800, 2200},
									//std::vector<double> {0, 1000, 1800, 2200}, std::vector<double> {0, 1000, 2300, 2800}));
									std::vector<double> {0, 800, 1600, 2000}, std::vector<double> {0, 800, 2100, 2600}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
