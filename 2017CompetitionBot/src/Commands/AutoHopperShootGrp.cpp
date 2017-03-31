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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, -850, -1675, -3425, -3625}, std::vector<double> {0, -850, -1675, -2775, -2975},
									std::vector<double> {0, -1000, -1750, -2750, -2850}, std::vector<double> {0, -1000, -1750, -3500, -3600}));

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
	AddSequential(new SilkyDriveCmd(std::vector<double> {0, 1010, 2080, 2680, 3200}, std::vector<double> {0, 330, 605, 880, 1380},
									std::vector<double> {0, 200, 525, 830, 1330}, std::vector<double> {0, 960, 2030, 2630, 3110}));

	//Pulse hopper
	AddParallel(new HopperPulseCmd(10.0));
	//Shoot
	AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
