#ifndef OI_H
#define OI_H

#include "WPILib.h"

const int DRIVER_CONTROLLER_PORT = 0;

const int DRIVE_SHIFTER_BTN = 1;
const int DRIVE_BELTARMS_OPENCLOSE_BTN = 2;
const int DRIVE_JAWS_OPENCLOSE_BTN = 3;
const int DRIVE_JAWS_INOUT_BTN = 4;

class OI
{
private:
	std::unique_ptr<Joystick> driverController;
	std::unique_ptr<JoystickButton> driveShifterBtn;
	std::unique_ptr<JoystickButton> driveBeltArmsOpenCloseBtn;
	std::unique_ptr<JoystickButton> driveJawsOpenCloseBtn;
	std::unique_ptr<JoystickButton> driveJawsInOutBtn;
public:
	OI();
};

#endif
