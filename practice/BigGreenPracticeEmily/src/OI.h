#ifndef OI_H
#define OI_H
const int DRIVER_CONTROLLER_PORT =0;
const int DRIVE_FORWARD_BTN = 1;

#include "WPILib.h"

class OI
{
private:
	std::unique_ptr<Joystick>driverController;
	std::unique_ptr<JoystickButton>driveForwardBtn;

public:
	OI();
};

#endif
