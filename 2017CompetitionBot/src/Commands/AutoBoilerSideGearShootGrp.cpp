#include "AutoBoilerSideGearShootGrp.h"

AutoBoilerSideGearShootGrp::AutoBoilerSideGearShootGrp() {
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
	AddSequential(new DriveStraightCmd(2369));
	AddSequential(new DriveTurnCmd(45));
	AddSequential(new DriveStraightCmd(2369));
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new DriveTurnCmd(TURN_TOWARDS_BOILER));
	AddSequential(new DriveStraightCmd(DRIVE_TOWARDS_BOILER));
	AddSequential(new ShootCmd());
}
