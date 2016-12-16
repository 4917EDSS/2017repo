#include "OI.h"
#include "Commands/DriveCmd.h"
#include "Commands/StopCmd.h"
#include "Commands/ShiftCmd.h"

OI::OI()
{
	// Process operator interface input here.
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	driveBtn.reset(new JoystickButton(driverController.get(), DRIVE_BTN));
	stopBtn.reset(new JoystickButton(driverController.get(), STOP_BTN));
	shiftBtn.reset(new JoystickButton(driverController.get(), SHIFT_BTN));
	driveBtn->WhenPressed(new DriveCmd);
	stopBtn->WhenPressed(new StopCmd);
	shiftBtn->WhenPressed(new ShiftCmd);
}
