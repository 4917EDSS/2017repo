#include "AutoShootGrp.h"
#include "SilkyDriveCmd.h"
#include <vector>

AutoShootGrp::AutoShootGrp() {
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

	// shoot
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, TEN_BALL_SHOT_TIME));
	// reverse turn - check turn
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000,-3700},std::vector<double> {0,-300,-1200}));
	// drive straight
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 200, 2000},std::vector<double> {0, 200, 2000}));
}
