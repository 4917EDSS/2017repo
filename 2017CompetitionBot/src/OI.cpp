#include "OI.h"

#include <WPILib.h>
#include "Commands/RunPickupCmd.h"
#include "Commands/LiftCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(driverController.get(), DRIVER_INTAKE_BTN));
	dIntakeBtn->WhenPressed(new RunPickupCmd);
	liftBtn.reset(new JoystickButton(driverController.get(), DRIVER_LIFT_BTN));
	liftBtn->WhileHeld (new LiftCmd);
}

std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
