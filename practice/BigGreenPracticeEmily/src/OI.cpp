#include "OI.h"
#include "Commands/DriveForwardCmd.h"
#include "Commands/StopDriveTrainCmd.h"

OI::OI()
{
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	// Process operator interface input here.

	driveForwardBtn.reset(new JoystickButton(driverController.get(),DRIVE_FORWARD_BTN));
	driveForwardBtn->WhenPressed(new DriveForwardCmd);

	stopDriveBtn.reset(new JoystickButton(driverController.get(), STOP_DRIVE_BTN));
	stopDriveBtn->WhenPressed(new StopDriveTrainCmd);
}
