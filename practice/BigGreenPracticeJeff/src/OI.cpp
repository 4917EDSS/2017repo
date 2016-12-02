#include "OI.h"
#include "Commands/DriveStraightCmd.h"

OI::OI()
{
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	driveStraightBtn.reset(new JoystickButton(DRIVER_CONTROLLER_PORT, DRIVE_STRAIGHT_BTN));
	driveStraightBtn->WhileHeld(new DriveStraightCmd);
	// Process operator interface input here.
}
