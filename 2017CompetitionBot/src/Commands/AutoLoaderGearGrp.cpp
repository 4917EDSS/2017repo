#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include "AHRSDriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "SilkyRotateCmd.h"
#include <vector>

AutoLoaderGearGrp::AutoLoaderGearGrp() {
	//Open gear flaps
//	AddParallel(new OpenGearFlapsCmd());

	//Drive to loader gear
	/*AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1451}, std::vector<double> {0, 930, 2230},
									std::vector<double> {0, 850, 2510}, std::vector<double> {0, 850, 1700}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1480}, std::vector<double> {0, 600, 1480},
									std::vector<double> {0, 600, 1435}, std::vector<double> {0, 600, 1435}));
									*/
	AddSequential(new AHRSDriveStraightCmd(LOADER_SIDE_APPROACH_DIST_BLUE, LOADER_SIDE_APPROACH_DIST_RED));
	AddSequential(new SilkyRotateCmd(-60));
	AddSequential(new AHRSDriveStraightCmd(DRIVE_TO_LOADER_SIDE_SHAFT));

	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -1500}, std::vector<double> {0, -1000, -2420},
									std::vector<double> {0, -1000, -2420}, std::vector<double> {0, -1000, -1500}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 7000}, std::vector<double> {0, 1000, 7000}));
}
