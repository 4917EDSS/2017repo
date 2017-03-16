#ifndef AutoHopperShootGrp_H
#define AutoHopperShootGrp_H
#include <WPILib.h>
#include "Commands/CommandGroup.h"
#include "Commands/ShootCmd.h"
#include "Commands/SpinUpCmd.h"

class AutoHopperShootGrp : public CommandGroup {
public:
	AutoHopperShootGrp();
};

#endif  // AutoHopperShootGrp_H
