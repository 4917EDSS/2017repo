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
const int OPERATOR_CONTROLLER_PORT = 1;
// Joystick Axis
const int DRIVER_LEFT_TANK_DRIVE_AXIS = 1;
const int DRIVER_RIGHT_TANK_DRIVE_AXIS = 3;

// Joystick Buttons
const int OPERATOR_LIFT_BTN = 4;
const int OPERATOR_LOWER_BTN = 3;
const int OPERATOR_INTAKE_BTN = 1;
const int OPERATOR_SHOOT_BTN = 2;
const int OPERATOR_INCREASE_SPEED_BTN = 6;
const int OPERATOR_DECREASE_SPEED_BTN = 5;
const int DRIVER_SHIFT_BTN =8;

class OI {
private:
	std::shared_ptr<frc::Joystick> driverController;
	std::shared_ptr<frc::Joystick> operatorController;
	std::shared_ptr<frc::JoystickButton>liftBtn;
	std::shared_ptr<frc::JoystickButton>lowerBtn;
	std::shared_ptr<frc::JoystickButton> dIntakeBtn;
	std::shared_ptr<frc::JoystickButton> shooterEnableBtn;
	std::shared_ptr<frc::JoystickButton> increaseSpeedBtn;
	std::shared_ptr<frc::JoystickButton> decreaseSpeedBtn;
	std::shared_ptr<frc::JoystickButton> driveTurnBtn;
	std::shared_ptr<frc::JoystickButton> shiftBtn;

public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();
	std::shared_ptr<frc::Joystick> getOperatorController();
};

#endif  // OI_H
