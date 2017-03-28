#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include <vector>

AutoLoaderGearGrp::AutoLoaderGearGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to gear
	if(blueside){
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
		AddSequential(new WaitCommand(GEAR_WAIT_TIME));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -1500}, std::vector<double> {0, -1000, -2420}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 7000}, std::vector<double> {0, 1000, 7000}));
	}else{

	}
}
