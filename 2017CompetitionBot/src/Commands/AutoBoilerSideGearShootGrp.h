#ifndef AutoBoilerSideGearShootGrp_H
#define AutoBoilerSideGearShootGrp_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"

class AutoBoilerSideGearShootGrp : public CommandGroup {
public:
	AutoBoilerSideGearShootGrp();
};

#endif  // AutoBoilerSideGearShootGrp_H
