#ifndef AutoBoilerGearShootGrp_H
#define AutoBoilerGearShootGrp_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"
#include "Commands/OpenGearFlapsCmd.h"

class AutoBoilerGearShootGrp : public CommandGroup {
public:
	AutoBoilerGearShootGrp();
};

#endif  // AutoBoilerGearShootGrp_H
