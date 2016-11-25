#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
}
