#include "OI.h"

#include <WPILib.h>
#include "Commands/RunPickupCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(driverController.get(), DRIVER_INTAKE_BTN));
	dIntakeBtn->WhenPressed(new RunPickupCmd);
}

std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
