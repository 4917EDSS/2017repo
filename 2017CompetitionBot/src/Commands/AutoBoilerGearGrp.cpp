#include <Commands/AutoBoilerGearGrp.h>
#include <vector>
#include "SilkyDriveCmd.h"
#include "OpenGearFlapsCmd.h"
#include "DriveStraightCmd.h"
#include "RotateToVisionCmd.h"
#include "ShootCmd.h"
#include "ToggleShifterCmd.h"
#include "SpinupCmd.h"
#include "HopperPulseCmd.h"

AutoBoilerGearGrp::AutoBoilerGearGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to boiler gear
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 2275}, std::vector<double> {0, 700, 1530}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1400}, std::vector<double> {0, 600, 1400}));

	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 700, 1530}, std::vector<double> {0, 700, 2275}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1400}, std::vector<double> {0, 600, 1400}));
	}
}
