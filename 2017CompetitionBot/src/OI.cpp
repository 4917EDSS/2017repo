#include "OI.h"

#include <WPILib.h>

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));
}

std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
