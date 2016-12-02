#ifndef OI_H
#define OI_H

#include "WPILib.h"

const int DRIVER_CONTROLLER_PORT = 0;
const int DRIVE_BTN = 1;
const int STOP_BTN = 2;

class OI
{
private:
	std::unique_ptr<Joystick> driverController;
	std::unique_ptr<JoystickButton> driveBtn;
	std::unique_ptr<JoystickButton> stopBtn;

public:
	OI();
};

#endif
