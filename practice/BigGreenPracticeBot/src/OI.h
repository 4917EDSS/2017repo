#ifndef OI_H
#define OI_H

#include "WPILib.h"

// Controllers
const int DRIVER_CONTROLLER_PORT = 0;

// Axes
const int TANKDRIVE_LEFT_CONTROLLER = DRIVER_CONTROLLER_PORT;
const int TANKDRIVE_LEFT_AXIS = 1;
const int TANKDRIVE_RIGHT_CONTROLLER = DRIVER_CONTROLLER_PORT;
const int TANKDRIVE_RIGHT_AXIS = 3;
const int INTAKE_CONTROL_CONTROLLER = DRIVER_CONTROLLER_PORT;
const int INTAKE_CONTROL_AXIS = 0;
const int LIFT_CONTROL_CONTROLLER = DRIVER_CONTROLLER_PORT;
const int LIFT_CONTROL_AXIS = 2;

// Buttons
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
	float getAxisValue(int controller, int axis);
};

#endif
