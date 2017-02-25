#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"

AutoLoaderGearGrp::AutoLoaderGearGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//Drive to gaar
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 2000, 4000}, std::vector<double> {0, 3000, 5000}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

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
