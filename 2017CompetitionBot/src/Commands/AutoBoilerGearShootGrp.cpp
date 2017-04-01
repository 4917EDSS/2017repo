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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 775 - 150, 2435 -150}, std::vector<double> {0, 775 - 150, 1625 - 150},
									std::vector<double> {0, 930 + 44, 1477 + 44}, std::vector<double> {0, 930 + 44, 2233 + 44}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 450, 1400}, std::vector<double> {0, 450, 1400},
									std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));

	//Wait at gear
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Reverse
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -300}, std::vector<double> {0, -200, -2300},
									std::vector<double> {0, -350, -2550}, std::vector<double> {0, -350, -550}));
	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1250, 2550, 2555}, std::vector<double> {0, 1250, 2050, 2225},
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
