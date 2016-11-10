#include "OI.h"
#include "Commands/ToggleShifterCmd.h"
#include "Commands/ToggleArmsOpenCloseCmd.h"
#include "Commands/ToggleJawsOpenCloseCmd.h"
#include "Commands/ToggleJawsInOutCmd.h"

OI::OI()
{
	// Process operator interface input here.
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));

	driveShifterBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_SHIFTER_BTN));
	driveShifterBtn->WhenPressed(new ToggleShifterCmd);

	driveBeltArmsOpenCloseBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_BELTARMS_OPENCLOSE_BTN));
	driveBeltArmsOpenCloseBtn->WhenPressed(new ToggleArmsOpenCloseCmd);

	driveJawsOpenCloseBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_JAWS_OPENCLOSE_BTN));
	driveJawsOpenCloseBtn->WhenPressed(new ToggleJawsOpenCloseCmd);

	driveJawsInOutBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_JAWS_INOUT_BTN));
	driveJawsInOutBtn->WhenPressed(new ToggleJawsInOutCmd);
}

float OI::getAxisValue(int controller, int axis)
{
	float value = 0.0;

	switch(controller)
	{
	// Driver controller axes
	case DRIVER_CONTROLLER_PORT:
		value = driverController->GetRawAxis(axis);
		break;

	// Unknown controller
	default:
		value = 0.0;
	}

	return value;
}
