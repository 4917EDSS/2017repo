#include "OI.h"

#include <WPILib.h>
#include "Commands/MeasureDistanceLidarCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new 	frc::Joystick(DRIVER_CONTROLLER_PORT));
	measureDistBtn.reset(new frc::JoystickButton(driverController.get(), DRIVER_MESURE_DIST_BUTTON));
	measureDistBtn->WhenPressed(new MeasureDistanceLidarCmd());
}

std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
