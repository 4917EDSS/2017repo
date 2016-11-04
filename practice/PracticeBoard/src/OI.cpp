#include "OI.h"
#include "Commands/DriveForwardCmd.h"
#include "Commands/DriveStopCmd.h"
#include "Commands/HoldButtonToTurnCmd.h"

OI::OI()
{
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));

	driveForwardBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_FORWARD_BTN));
	driveForwardBtn->WhenPressed(new DriveForwardCmd);

	driveStopBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_STOP_BTN));
	driveStopBtn->WhenPressed(new DriveStopCmd);

	driveSingleBtn.reset(new JoystickButton((Joystick *)(driverController.get()), DRIVE_SINGLE_BTN));
		driveSingleBtn->WhenPressed(new HoldButtonToTurnCmd());
}
