#include <Commands/AutoHopperShootGrp.h>
#include "SilkyDriveCmd.h"
#include "ShootCmd.h"
#include "SpinUpCmd.h"
#include <vector>
#include "SetHopperOpenCmd.h"
#include "OpenGearFlapsCmd.h"
#include "HopperPulseCmd.h"
#include "RunPickupCmd.h"
#include "SetIntakeCmd.h"


AutoHopperShootGrp::AutoHopperShootGrp() {
	//Open hopper and gear flaps
	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));

	//Drive to hopper
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -850, -1600, -3350, -3450}, std::vector<double> {0, -850, -1600, -2700, -2800},
									std::vector<double> {0, -850, -1600, -2700, -2800}, std::vector<double> {0, -850, -1600, -3350, -3450}));

	//Open robot hopper
	AddParallel(new SetHopperOpenCmd(false));
	//Reverse shooter for intake
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED, HOPPER_RECEIVE_TIME));
	//Wait
	AddSequential(new WaitCommand(HOPPER_WAIT_TIME));
	//Spin up shooter
	AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
	//Turn intake bar on
	AddParallel(new SetIntakeCmd(true));
	AddParallel(new RunPickupCmd());

	//Drive to shooter
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1010, 2080, 2680, 3160}, std::vector<double> {0, 330, 605, 880, 1380},
									std::vector<double> {0, 330, 605, 880, 1380}, std::vector<double> {0, 1010, 2080, 2680, 3160}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
