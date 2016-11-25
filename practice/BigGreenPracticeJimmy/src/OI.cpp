#include "OI.h"

OI::OI()
{
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	// Process operator interface input here.
}
