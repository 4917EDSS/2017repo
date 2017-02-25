#include <Commands/AutoHopperShootGrp.h>
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include <vector>

AutoHopperShootGrp::AutoHopperShootGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//For forwards to hopper
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 450, 2650, 2750, 3450}, std::vector<double> {0, 450, 4000, 4100, 4740}));
	//Backwards to hopper
	AddSequential(new SilkyDriveCmd({0, -250, -3300, -4100, -4940}, {0, -250, -1950, -2750, -3540}));
	AddSequential(new WaitCommand(HOPPER_WAIT_TIME));
	AddSequential(new SilkyDriveCmd({0, 1000, 2000, 3200}, {0, 200, 500, 1200}));
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
}
