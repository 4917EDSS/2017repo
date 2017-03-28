#include "AutoLoaderGearHopperLoadGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include "SetHopperOpenCmd.h"
#include "ToggleShifterCmd.h"
#include "ShootCmd.h"
#include <vector>

AutoLoaderGearHopperLoadGrp::AutoLoaderGearHopperLoadGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to hopper gear
	if(blueSide){
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
	} else{
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 2230}, std::vector<double> {0, 930, 1442}));
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
	}

	AddSequential(new WaitCommand(GEAR_WAIT_TIME * 3));

	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -2700, -2900, -3800}, std::vector<double> {0, -200, -2000, -2500, -3100}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -200, -2000, -2500, -3100}, std::vector<double> {0, -1000, -2700, -2900, -3800}));
	}

	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));

	if(blueSide) {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -550}, std::vector<double> {0, -75, -400}));
	} else {
		AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -400}, std::vector<double> {0, -75, -550}));
	}

	AddParallel(new SetHopperOpenCmd(false));
}
