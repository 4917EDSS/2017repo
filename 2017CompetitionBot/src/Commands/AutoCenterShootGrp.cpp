#include <Commands/AutoCenterShootGrp.h>
#include <Commands/ShootCmd.h>
#include "AutoLoadStraightGrp.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"

AutoCenterShoot::AutoCenterShoot() {
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
	AddSequential(new DriveStraightCmd(LOAD_STRAIGHT_DIST));
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new DriveStraightCmd(BACK_OFF_OF_SHAFT_DIST));
	AddSequential(new DriveTurnCmd(TURN_TO_BOILER_DEGREE));
	AddSequential(new DriveStraightCmd(CENTER_TO_BOILER));
	AddSequential(new ShootCmd());



}
