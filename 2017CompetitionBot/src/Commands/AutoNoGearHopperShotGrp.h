#ifndef AutoNoGearHopperShotGrp_H
#define AutoNoGearHopperShotGrp_H

#include <Commands/CommandGroup.h>
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "ShootCmd.h"
#include "WPILib.h"

class AutoNoGearHopperShotGrp : public CommandGroup {
public:
	AutoNoGearHopperShotGrp();
};

#endif  // AutoNoGearHopperShotGrp_H
