#include <Commands/AutoBoilerGearShootGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "DriveStraightCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"

AutoBoilerGearShootGrp::AutoBoilerGearShootGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to boiler gear
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2275}, std::vector<double> {0, 700, 1530}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1400}, std::vector<double> {0, 600, 1400}));
	} else {

	}

	//Wait at gear
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	//Start up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));

	//Drive to boiler
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -400}, std::vector<double> {0, -200, -2500}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 2300, 2800}, std::vector<double> {0, 1000, 1800, 2200}));
	} else {

	}

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
