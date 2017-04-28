#include <Commands/AutoBoilerGearShootGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"
#include "AHRSDriveStraightCmd.h"
#include "SilkyRotateCmd.h"
#include "ShootCmdGrp.h"

AutoBoilerGearShootGrp::AutoBoilerGearShootGrp() {
	// drive to boiler gear
	AddSequential(new AHRSDriveStraightCmd(BOILER_SIDE_APPROACH_DIST_BLUE, BOILER_SIDE_APPROACH_DIST_RED));
	AddSequential(new SilkyRotateCmd(60));
	AddSequential(new AHRSDriveStraightCmd(DRIVE_TO_BOILER_SIDE_SHAFT_BLUE, DRIVE_TO_BOILER_SIDE_SHAFT_RED));
	// open gear flaps
	AddSequential(new OpenGearFlapsCmd());
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	// start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
	// reverse
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -300}, std::vector<double> {0, -200, -2350}, std::vector<double> {0, -350, -2550}, std::vector<double> {0, -350, -550}));
	// close gear flaps
	AddSequential(new OpenGearFlapsCmd(false));
	// drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 2300, 2575}, std::vector<double> {0, 1000, 1900, 2130}, std::vector<double> {0, 1000, 1900, 1993}, std::vector<double> {0, 1000, 2400, 2575}));
	AddSequential(new ShootCmdGrp());
}
