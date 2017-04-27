#include <Commands/AutoCenterGearShootGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"
#include "Commands/OpenGearFlapsCmd.h"
#include "Commands/SpinUpCmd.h"
#include "AHRSDriveStraightCmd.h"
#include "Commands/HopperPulseCmd.h"
AutoCenterGearShootGrp::AutoCenterGearShootGrp() {
	//Open gear flaps
	//AddParallel(new OpenGearFlapsCmd());

	//Drive straight to peg
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));
	AddSequential(new AHRSDriveStraightCmd(LOAD_STRAIGHT_DIST_BLUE, LOAD_STRAIGHT_DIST_RED));

	//Open gear flaps
	AddSequential(new OpenGearFlapsCmd());
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

	//Reverse to right
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1850},std::vector<double> {0,-150,-500},
									std::vector<double> {0,-150,-500},std::vector<double> {0, -150,-1775}));

	//Close Gear Flaps
	AddSequential(new OpenGearFlapsCmd(false));

	//Start shooter motor
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1200 + 400, 2175 + 400, 3210 + 400}, std::vector<double> {0, 1200 + 400, 2575 + 400, 3875 + 400},
									std::vector<double> {0, 1600, 2800, 4225}, std::vector<double> {0, 1600, 2350, 3679}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(15.0));
	//Shoot
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, BOILER_SHOOT_TIME_1));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
