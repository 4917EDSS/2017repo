#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include <vector>

AutoLoaderGearGrp::AutoLoaderGearGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	//Drive to loader gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230},
									std::vector<double> {0, 700, 2360}, std::vector<double> {0, 700, 1550}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475},
									std::vector<double> {0, 600, 1450}, std::vector<double> {0, 600, 1450}));

	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -1500}, std::vector<double> {0, -1000, -2420},
									std::vector<double> {0, -1000, -2420}, std::vector<double> {0, -1000, -1500}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 7000}, std::vector<double> {0, 1000, 7000}));
}
