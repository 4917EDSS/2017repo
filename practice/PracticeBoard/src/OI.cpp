#include "OI.h"
#include "Commands/DriveForwardCmd.h"
#include "Commands/DriveStopCmd.h"

OI::OI()
{
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));

	driveForwardBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_FORWARD_BTN));
	driveForwardBtn->WhenPressed(new DriveForwardCmd);

	driveStopBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_STOP_BTN));
	driveStopBtn->WhenPressed(new DriveStopCmd);
}
