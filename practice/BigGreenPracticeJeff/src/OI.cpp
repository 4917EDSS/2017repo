#include "OI.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "Commands/StopCmd.h"
#include "Commands/ShiftCmd.h"

OI::OI()
{
	// Process operator interface input here.
	driverController.reset(new Joystick(DRIVER_CONTROLLER_PORT));
	stopBtn.reset(new JoystickButton(driverController.get(), STOP_BTN));
	shiftBtn.reset(new JoystickButton(driverController.get(), SHIFT_BTN));
	driveBtn.reset(new JoystickButton(driverController.get(), DRIVE_BTN));
	stopBtn->WhenPressed(new StopCmd);
	shiftBtn->WhenPressed(new ShiftCmd);
	driveBtn->WhenPressed(new DriveWithJoystickCmd);

}
float OI::GetRightVer(){
	return driverController->GetRawAxis(RIGHT_STICK);
}
float OI::GetLeftVer(){
	return -driverController->GetRawAxis(LEFT_STICK);
}
