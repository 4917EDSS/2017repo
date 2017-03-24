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
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	// numbers need to be switched to variables

	//Open Gear Flaps
	AddParallel(new OpenGearFlapsCmd());
	//Drive to gaar (From Key)
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1217, 2519, 3230}, std::vector<double> {0, 1180, 2114, 2415}));
	//Drive to gear (From Boiler)
//	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 200, 2160, 3810}, std::vector<double> {0, 200, 1350, 3000}));
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2460, 3110}, std::vector<double> {0, 700, 1650, 2300}));
	//Go to low gear
	//full silky to gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2275}, std::vector<double> {0, 700, 1500}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1300}, std::vector<double> {0, 600, 1300}));
	/*AddSequential(new ToggleShifterCmd());
	//Align with Vision
	AddSequential(new RotateToVisionCmd(2));
	//Go to high gear
	AddSequential(new ToggleShifterCmd());
	//Drive Straight
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 300, 750}, std::vector<double> {0, 300, 750}));
	*/
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -400}, std::vector<double> {0, -200, -2500}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 2300, 2800}, std::vector<double> {0, 1000, 1800, 2200}));
	AddParallel(new HopperPulseCmd(10.0));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
