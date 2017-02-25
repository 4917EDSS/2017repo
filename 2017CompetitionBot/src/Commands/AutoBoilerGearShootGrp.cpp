#include <Commands/AutoBoilerGearShootGrp.h>
#include "SilkyDriveCmd.h"

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

	//Drive to gaar
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 500, 3800}, std::vector<double> {0, 500, 3000}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Reverse to left
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-300},std::vector<double> {0,-150,-1500}));
	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 50, 3000},std::vector<double> {0, 50, 2500}));
	//Shooot!!!
	AddSequential(new ShootCmd());
}
