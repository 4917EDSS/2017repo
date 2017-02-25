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

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1886 / 2, 1886}, std::vector<double> {0, 1886 / 2, 1886}));
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new SilkyDriveCmd({0, -150,-3000}, {0,-150,-300}));
	//AddSequential(new SilkyDriveCmd({0, 2000, 3500}, {0, 2500, 3500}));

	//AddSequential(new ShootCmd());
}
