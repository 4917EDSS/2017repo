#ifndef OI_H
#define OI_H

#include <WPILib.h>

constexpr int DRIVER_CONTROLLER_PORT = 0;

// Joystick Axis
constexpr int DRIVER_LEFT_TANK_DRIVE_AXIS = 1;
constexpr int DRIVER_RIGHT_TANK_DRIVE_AXIS = 3;

// Joystick buttons
constexpr int DRIVER_MESURE_DIST_BUTTON = 1;

class OI {
public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();

private:
	std::shared_ptr<frc::Joystick> driverController;
	std::shared_ptr<frc::JoystickButton> measureDistBtn;
};

#endif  // OI_H
