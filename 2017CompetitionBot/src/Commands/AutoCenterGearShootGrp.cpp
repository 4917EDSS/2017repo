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

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive straight to peg
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));
	}

	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

	//Reverse to right
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -150,-1700},std::vector<double> {0,-150,-500}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0,-150,-500},std::vector<double> {0, -150,-1700}));
	}

	//Close Gear Flaps
	AddParallel(new OpenGearFlapsCmd(false));

	//Start shooter motor
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1725, 2703, 3528}, std::vector<double> {0, 1725, 3150, 4100}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1725, 3150, 4100}, std::vector<double> {0, 1725, 2703, 3528}));
	}

	//Pulse hopper
	AddParallel(new HopperPulseCmd(15.0));
	//Shoot
	AddSequential(new ShootCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED, BOILER_SHOOT_TIME_1));
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));

}
