#include "AutoCenterGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include "OpenGearFlapsCmd.h"
#include "RotateToVisionCmd.h"
#include "ToggleShifterCmd.h"
#include "AHRSDriveStraightCmd.h"
#include "DesperateCenterGearGrp.h"
#include <vector>

AutoCenterGearGrp::AutoCenterGearGrp() {
	//Open gear flaps
	AddParallel(new OpenGearFlapsCmd());

	AddSequential(new AHRSDriveStraightCmd(LOAD_STRAIGHT_DIST, 0.7));
	AddSequential(new DesperateCenterGearGrp());
	//Drive to gear
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 1882}, std::vector<double> {0, 1000, 1882}));

}
