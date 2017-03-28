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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2275}, std::vector<double> {0, 700, 1530},
									std::vector<double> {0, 650, 1480}, std::vector<double> {0, 650, 2230}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1400}, std::vector<double> {0, 600, 1400}));

	//Wait at gear
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -300}, std::vector<double> {0, -200, -2500},
									std::vector<double> {0, -200, -2500}, std::vector<double> {0, -200, -400}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 2300, 2800}, std::vector<double> {0, 1000, 1800, 2200},
									std::vector<double> {0, 1000, 1800, 2200}, std::vector<double> {0, 1000, 2300, 2800}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
