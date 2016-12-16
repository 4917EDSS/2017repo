#include "OI.h"
#include "Commands/DriveForwardCmd.h"
OI::OI() {

	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	driveForwardBtn.reset(new JoystickButton(driverController.get(), DRIVE_FORWARD_BTN));
	driveForwardBtn->WhenPressed(new DriveForwardCmd());
	// Process operator interface input here.
}
