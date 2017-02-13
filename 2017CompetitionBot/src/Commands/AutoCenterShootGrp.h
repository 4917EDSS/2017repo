#ifndef AutoCenterShootGrp_H
#define AutoCenterShootGrp_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ShootCmd.h"

class AutoCenterShootGrp : public CommandGroup {
public:
	AutoCenterShootGrp();
};

#endif  // AutoCenterShootGrp_H
