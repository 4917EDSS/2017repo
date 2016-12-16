#ifndef OI_H
#define OI_H
const int DRIVER_CONTROLLER_PORT =0;
const int DRIVE_FORWARD_BTN = 1;
const int STOP_DRIVE_BTN = 2;

#include "WPILib.h"

class OI
{
private:
	std::unique_ptr<Joystick>driverController;
	std::unique_ptr<JoystickButton>driveForwardBtn;
	std::unique_ptr<JoystickButton>stopDriveBtn;
public:
	OI();
};

#endif
