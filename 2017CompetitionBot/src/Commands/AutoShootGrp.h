#ifndef AutoShootGrp_H
#define AutoShootGrp_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"

class AutoShootGrp : public CommandGroup {
public:
	AutoShootGrp();
};

#endif  // AutoShootGrp_H
