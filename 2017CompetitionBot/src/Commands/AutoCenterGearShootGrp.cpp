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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1700},std::vector<double> {0,-150,-500},
									std::vector<double> {0,-150,-500},std::vector<double> {0, -150,-1775}));

	//Close Gear Flaps
	AddParallel(new OpenGearFlapsCmd(false));

	//Start shooter motor
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1625, 2600, 3650}, std::vector<double> {0, 1625, 3000, 4250},
									std::vector<double> {0, 900 + 810, 2100 + 810, 3900 + 235}, std::vector<double> {0, 900 + 810, 1650 + 810, 3400 + 235}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(15.0));
	//Shoot
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, BOILER_SHOOT_TIME_1));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
