#include "ShootCmdGrp.h"
#include "HopperPulseCmd.h"
#include "ShootCmd.h"

ShootCmdGrp::ShootCmdGrp() {
	AddParallel(new HopperPulseCmd(50.0));
	AddParallel(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
}
