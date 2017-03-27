#include "AutoLoaderGearHopperLoadGrp.h"
#include "SilkyDriveCmd.h"
#include "RotateToVisionCmd.h"
#include "OpenGearFlapsCmd.h"
#include "SetHopperOpenCmd.h"
#include "ToggleShifterCmd.h"
#include "ShootCmd.h"
#include <vector>

AutoLoaderGearHopperLoadGrp::AutoLoaderGearHopperLoadGrp() {
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

	// RED SIDE AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1300, 1600, 3200}, std::vector<double> {0, 1300, 2400, 3850}));

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 930, 1442}, std::vector<double> {0, 930, 2230}));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 600, 1475}, std::vector<double> {0, 600, 1475}));
	//Wait
	AddSequential(new WaitCommand(GEAR_WAIT_TIME * 3));

	/* RED SIDE AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -2700, -2900, -3800}, std::vector<double> {0, -200, -2000, -2500, -3100}));
	AddParallel(new OpenGearFlapsCmd());
	AddParallel(new SetHopperOpenCmd(true));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -550}, std::vector<double> {0, -75, -400}));
	AddParallel(new SetHopperOpenCmd(false)); */

	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -1000, -2700, -2900, -3800}, std::vector<double> {0, -200, -2000, -2500, -3100}));
	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -75, -550}, std::vector<double> {0, -75, -400}));
	AddParallel(new SetHopperOpenCmd(false));
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
