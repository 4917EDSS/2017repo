#include "DesperateCenterGearGrp.h"
#include "AHRSDriveStraightCmd.h"
#include "SilkyRotateCmd.h"
#include "OpenGearFlapsCmd.h"


DesperateCenterGearGrp::DesperateCenterGearGrp() {
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
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new AHRSDriveStraightCmd(-500));
	AddParallel(new OpenGearFlapsCmd(false));
	AddSequential(new SilkyRotateCmd(5));
	AddSequential(new AHRSDriveStraightCmd(500));
	AddParallel(new OpenGearFlapsCmd());
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new AHRSDriveStraightCmd(-500));
	AddParallel(new OpenGearFlapsCmd(false));
	AddSequential(new SilkyRotateCmd(-10));
	AddSequential(new AHRSDriveStraightCmd(500));
	AddParallel(new OpenGearFlapsCmd());
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));


}
