#include "AutoCenterGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include "OpenGearFlapsCmd.h"
#include "RotateToVisionCmd.h"
#include "ToggleShifterCmd.h"
#include <vector>

AutoCenterGearGrp::AutoCenterGearGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to gear
	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));
	}

}
