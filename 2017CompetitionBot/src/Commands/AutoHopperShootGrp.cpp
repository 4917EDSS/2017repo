#include <Commands/AutoHopperShootGrp.h>
#include "SilkyDriveCmd.h"
#include "ShootCmd.h"
#include "SpinUpCmd.h"
#include <vector>
#include "SetHopperOpenCmd.h"


AutoHopperShootGrp::AutoHopperShootGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//For forwards to hopper
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 450, 2650, 2750, 3450}, std::vector<double> {0, 450, 4000, 4100, 4740}));
	//Backwards to hopper
	//AddSequential(new SilkyDriveCmd({0, -3000, -3300, -4100, -4940}, {0, -250, -1950, -2750, -3540}));

	//Open Hopper
	AddParallel(new SetHopperOpenCmd());
	AddSequential(new SilkyDriveCmd({0, -1000, -2000, -2300, -3300, -3500}, {0, -1000, -2000, -2300, -2500, -2700}));
	//Close Hopper
	AddParallel(new SetHopperOpenCmd(false));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED, HOPPER_RECEIVE_TIME));
	AddSequential(new WaitCommand(HOPPER_WAIT_TIME));
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
	AddSequential(new SilkyDriveCmd({0, 1000, 2000, 3200, 3700}, {0, 200, 500, 1200, 1700}));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));

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
