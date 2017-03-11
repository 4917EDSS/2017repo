#include <Commands/AutoBoilerGearShootGrp.h>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"

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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1250, 2577, 3644}, std::vector<double> {0, 1072, 2032, 3008}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

}
