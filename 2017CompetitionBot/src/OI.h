#ifndef OI_H
#define OI_H

#include "WPILib.h"

// Joystick Ports
const int DRIVER_CONTROLLER_PORT = 0;

// Joystick Axis
const int DRIVER_LEFT_TANK_DRIVE_AXIS = 1;
const int DRIVER_RIGHT_TANK_DRIVE_AXIS = 3;

// Joystick Buttons

const int DRIVER_LIFT_BTN = 4;
class OI {
private:
	std::shared_ptr<frc::Joystick> driverController;
	std::shared_ptr<frc::JoystickButton>liftBtn;
public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();
};

#endif  // OI_H
