#ifndef OI_H
#define OI_H

#include "WPILib.h"

const int DRIVER_CONTROLLER_PORT = 0;
const int DRIVE_STRAIGHT_BTN = 1;

class OI
{
private:
	std::unique_ptr<Joystick> driverController;
	std::unique_ptr<JoystickButton> driveStraightBtn;

public:
	OI();
};

#endif
