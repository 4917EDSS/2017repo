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

AutoBoilerGearShootGrp::AutoBoilerGearShootGrp() {
	//Open gear flaps
//	AddParallel(new OpenGearFlapsCmd());

	int BOILER_SIDE_APPROACH_DIST_BLUE = LOADER_SIDE_APPROACH_DIST_BLUE;
	int BOILER_SIDE_APPROACH_DIST_RED = LOADER_SIDE_APPROACH_DIST_RED;
	int DRIVE_TO_BOILER_SIDE_SHAFT_BLUE = DRIVE_TO_LOADER_SIDE_SHAFT_BLUE;
	int DRIVE_TO_BOILER_SIDE_SHAFT_RED = DRIVE_TO_LOADER_SIDE_SHAFT_RED;

	AddSequential(new AHRSDriveStraightCmd(BOILER_SIDE_APPROACH_DIST_BLUE, BOILER_SIDE_APPROACH_DIST_RED));
	AddSequential(new SilkyRotateCmd(60));
	AddSequential(new AHRSDriveStraightCmd(DRIVE_TO_BOILER_SIDE_SHAFT_BLUE, DRIVE_TO_BOILER_SIDE_SHAFT_RED));
	//Open gear flaps
	AddSequential(new OpenGearFlapsCmd());
	//Wait at gear
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Reverse
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -300}, std::vector<double> {0, -200, -2350},
									std::vector<double> {0, -350, -2550}, std::vector<double> {0, -350, -550}));
	//Close Flaps
	AddSequential(new OpenGearFlapsCmd(false));
	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 2100, 2575}, std::vector<double> {0, 600, 1700, 2130},
	/* John Example For Future Use:
	int delta1L = 0;
	int delta2L = 0;
	int delta3L = 0;
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, delta1, delta1 + delta2, delta1 + delta2 + delta3}, std::vector<double> {}),
	 	 	 	 	 	 	 	 	 std::vector<double> {}, std::vector<double> {}
	 */
									std::vector<double> {0, 400, 1400, 1643}, std::vector<double> {0, 400, 1900, 2225}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
