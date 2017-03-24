#include <Commands/AutoCenterGearShootGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"
#include "Commands/OpenGearFlapsCmd.h"
#include "Commands/SpinUpCmd.h"
#include "Commands/HopperPulseCmd.h"
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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1886 / 2, 1848}, std::vector<double> {0, 1886 / 2, 1848}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Reverse to right
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1700},std::vector<double> {0,-150,-500}));
	//Close Gear Flaps
	AddParallel(new OpenGearFlapsCmd(false));
	//Start shooter motor
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
	//Drive to boiler
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 100, 3300}, std::vector<double> {0, 150, 4100}));//St1raight to Hopper
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1425, 2353, 3275}, std::vector<double> {0, 1525, 3000, 4100}));//More of a Turn
	//Shoot
	AddParallel(new HopperPulseCmd(15.0));
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, BOILER_SHOOT_TIME_1));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));

}
