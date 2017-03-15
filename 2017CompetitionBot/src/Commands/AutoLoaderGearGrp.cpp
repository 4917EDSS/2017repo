#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "ToggleShifterCmd.h"

AutoLoaderGearGrp::AutoLoaderGearGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//Drive to gaar
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1050, 1400, 2800}, std::vector<double> {0, 1050, 1850, 3700}));

	//Open Gear Flaps
	AddParallel(new OpenGearFlapsCmd());
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 650, 1500, 2800}, std::vector<double> {0, 650, 2500, 3500}));
	//Drive Towards Gear
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1050, 1900}, std::vector<double> {0, 1050, 2800}));
	//Shifting
	AddSequential(new ToggleShifterCmd());
	//Auto Correct
	AddSequential(new RotateToVisionCmd(2));
	//Shifting111
	AddSequential(new ToggleShifterCmd());
	//Keep Driving Straight
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 500, 1300}, std::vector<double> {0, 500, 1300}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));

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
}
