#ifndef AutoCenterGearShootGrp_H
#define AutoCenterGearShootGrp_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"

class AutoCenterGearShootGrp : public CommandGroup {
public:
	AutoCenterGearShootGrp();
};

#endif  // AutoCenterGearShootGrp_H
