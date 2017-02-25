#include <Commands/AutoCenterGearShootGrp.h>
#include "SilkyDriveCmd.h"
AutoCenterGearShootGrp::AutoCenterGearShootGrp() {
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

	//   Drive Straight to center peg
	//   Wait for gear
	//   R

	//Drive Straight to peg
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1886 / 2, 1886}, std::vector<double> {0, 1886 / 2, 1886}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Reverse to right
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1500},std::vector<double> {0,-150,-300}));
	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 50, 3500}, std::vector<double> {0, 50, 4300}));
	//Shoot
	AddSequential(new ShootCmd());
}
