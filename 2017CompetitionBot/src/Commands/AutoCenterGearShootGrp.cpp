#include <Commands/AutoCenterGearShootGrp.h>
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
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

	//Open Gear Flaps
	AddParallel(new OpenGearFlapsCmd());
	//Drive Straight to peg
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1886 / 2, 2000}, std::vector<double> {0, 1886 / 2, 2000}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Reverse to right
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1700},std::vector<double> {0,-150,-500}));
	//Drive to boiler
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 100, 3300}, std::vector<double> {0, 150, 4100}));//Straight to Hopper
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 850, 2253, 3475}, std::vector<double> {0, 1025, 2900, 4250}));//More of a Turn
	//Close Gear Flaps
	AddParallel(new OpenGearFlapsCmd(false));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));

}
