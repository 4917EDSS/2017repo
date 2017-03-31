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
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive straight to peg
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));

	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

	//Reverse to right
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1850},std::vector<double> {0,-150,-500},
									std::vector<double> {0,-150,-500},std::vector<double> {0, -150,-1775}));

	//Close Gear Flaps
	AddParallel(new OpenGearFlapsCmd(false));

	//Start shooter motor
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1425, 2400, 3450}, std::vector<double> {0, 1425, 2800, 4050},
									std::vector<double> {0, 900 + 900, 2100 + 900, 3900 + 325}, std::vector<double> {0, 900 + 900, 1650 + 900, 3400 + 279}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(15.0));
	//Shoot
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, BOILER_SHOOT_TIME_1));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
