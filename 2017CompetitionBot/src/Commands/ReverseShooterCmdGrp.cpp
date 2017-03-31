#include "ReverseShooterCmdGrp.h"

#include "ShootCmd.h"
#include "LiftCmd.h"

ReverseShooterCmdGrp::ReverseShooterCmdGrp() {
	AddParallel(new LiftCmd(-1.0));
	AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED));
}
