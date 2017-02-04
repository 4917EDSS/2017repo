#ifndef AutoNoGearShotGrp_H
#define AutoNoGearShotGrp_H

#include <Commands/CommandGroup.h>
#include "ShootWhileHeldCmd.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "WPILib.h"

class AutoNoGearShotGrp : public CommandGroup {
public:
	AutoNoGearShotGrp();
};

#endif  // AutoNoGearShotGrp_H
