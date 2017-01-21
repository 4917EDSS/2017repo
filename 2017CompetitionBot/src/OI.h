#ifndef OI_H
#define OI_H

#include "WPILib.h"

/*
 * ON LOGITECH CONTROLLER:
 * X = 1
 * A = 2
 * B = 3
 * Y = 4
 * LB = 5
 * RB = 6
 * LT = 7
 * RT = 8
 * Select = 9
 * Start = 10
 * L3 = 11
 * R3 = 12
 * Left Vertical = 1
 * Left Horizontal = 0
 * Right Vertical = 3
 * Right Horizontal = 2
 *
 */

// Joystick Ports
const int DRIVER_CONTROLLER_PORT = 0;

// Joystick Axis
const int DRIVER_LEFT_TANK_DRIVE_AXIS = 1;
const int DRIVER_RIGHT_TANK_DRIVE_AXIS = 3;

// Joystick Buttons
const int DRIVER_LIFT_BTN = 4;
const int DRIVER_LOWER_BTN = 3;
const int DRIVER_INTAKE_BTN = 1;
const int DRIVER_SHOOT_BTN = 2;
const int DRIVER_DRIVETURN_BTN =5;

class OI {
private:
	std::shared_ptr<frc::Joystick> driverController;
	std::shared_ptr<frc::JoystickButton>liftBtn;
	std::shared_ptr<frc::JoystickButton>lowerBtn;
	std::shared_ptr<frc::JoystickButton> dIntakeBtn;
	std::shared_ptr<frc::JoystickButton> shooterEnableBtn;
	std::shared_ptr<frc::JoystickButton> driveTurnBtn;

public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();
};

#endif  // OI_H
