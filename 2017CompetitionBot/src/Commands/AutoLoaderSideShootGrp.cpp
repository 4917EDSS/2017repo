#include "AutoLoaderSideShootGrp.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "ShootCmd.h"
#include <WPILib.h>

AutoLoaderSideShootGrp::AutoLoaderSideShootGrp() {
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

	AddSequential(new DriveStraightCmd(LOADER_SIDE_APPROACH_DIST));
	AddSequential(new DriveTurnCmd(TURN_TO_LOADER_SIDE_SHAFT));
	AddSequential(new DriveStraightCmd(DRIVE_TO_LOADER_SIDE_SHAFT));
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new DriveStraightCmd(BACK_OFF_OF_SHAFT_DIST));
	AddSequential(new DriveTurnCmd(LOADER_SHAFT_TO_BOILER_ANGLE));
	AddSequential(new DriveStraightCmd(LOADER_SHAFT_TO_BOILER_DIST));
	AddSequential(new ShootCmd());


}
