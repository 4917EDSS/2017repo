#include "AutoCenterGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RobotMap.h"
#include "OpenGearFlapsCmd.h"
#include "RotateToVisionCmd.h"
#include "ToggleShifterCmd.h"

AutoCenterGearGrp::AutoCenterGearGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	//Open Gear Flaps
	AddParallel(new OpenGearFlapsCmd());
	//Drive halfway
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 500, 1000}, std::vector<double> {0, 500, 1000}));
	//Shift Down
	AddSequential(new ToggleShifterCmd());
	//Auto Correct
	AddSequential(new RotateToVisionCmd(2));
	//Shift Up
	AddSequential(new ToggleShifterCmd());
	//Finish Driving
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 500, 1000}, std::vector<double> {0, 500, 1000}));
}
