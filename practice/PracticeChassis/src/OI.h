#ifndef OI_H
#define OI_H

#include <WPILib.h>

constexpr int DRIVER_CONTROLLER_PORT = 0;

// Joystick Axis
constexpr int DRIVER_LEFT_TANK_DRIVE_AXIS = 1;
constexpr int DRIVER_RIGHT_TANK_DRIVE_AXIS = 3;

class OI {
public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();

private:
	std::shared_ptr<frc::Joystick> driverController;

};

#endif  // OI_H
