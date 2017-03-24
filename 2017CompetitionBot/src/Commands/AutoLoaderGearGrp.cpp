#include "AutoLoaderGearGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include <vector>

AutoLoaderGearGrp::AutoLoaderGearGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//Drive to gaar;

	//Open Gear Flaps
	AddParallel(new OpenGearFlapsCmd());
	//Drive Towards Gear
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1050, 1900}, std::vector<double> {0, 1050, 2800}));
	//Keep Driving Straight
	//AddSequential(new SilkyDriveCmd(std::vector<double> {0, 500, 1300}, std::vector<double> {0, 500, 1300}));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1300, 1600, 3200}, std::vector<double> {0, 1300, 2400, 3850}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -1500}, std::vector<double> {0, -1000, -2420}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1000, 7000}, std::vector<double> {0, 1000, 7000}));
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
