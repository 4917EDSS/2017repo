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
const int OPERATOR_LOWER_BTN = 10;
const int OPERATOR_INTAKE_BTN = 2;
//const int OPERATOR_SHOOT_BTN = 2;
const int OPERATOR_KILL_EVERYTHING_BTN = 11;
const int OPERATOR_INCREASE_SPEED_BTN = 6;
const int OPERATOR_DECREASE_SPEED_BTN = 5;
const int OPERATOR_GEAR_FLAP_BTN = 1;
const int OPERATOR_SHRINK_HOPPER_BTN = 3;
const int OPERATOR_BOILER_SHOT_BTN = 7;
const int OPERATOR_KEY_SHOT_BTN = 8;
const int OPERATOR_REVERSE_SHOOTER_BTN = 9;

const int DRIVER_KILL_EVERYTHING_BTN = 11;
const int DRIVER_SHIFT_BTN = 8;
const int DRIVER_FORWARDS_BTN = 9;
const int DRIVER_SWITCH_CAM_BTN = 1;
const int DRIVER_ROTATE_BTN = 2;
const int DRIVER_DRIVE_TURN_BTN = 3;

class OI {
private:
	std::shared_ptr<frc::Joystick> driverController;
	std::shared_ptr<frc::Joystick> operatorController;
	std::shared_ptr<frc::JoystickButton>liftBtn;
	std::shared_ptr<frc::JoystickButton>lowerBtn;
	std::shared_ptr<frc::JoystickButton> dIntakeBtn;
	//std::shared_ptr<frc::JoystickButton> shooterEnableBtn;
	std::shared_ptr<frc::JoystickButton> increaseSpeedBtn;
	std::shared_ptr<frc::JoystickButton> decreaseSpeedBtn;
	std::shared_ptr<frc::JoystickButton> driveTurnBtn;
	std::shared_ptr<frc::JoystickButton> shiftBtn;
	std::shared_ptr<frc::JoystickButton> driveForwardsBtn;
	std::shared_ptr<frc::JoystickButton> openGearFlapsBtn;
	std::shared_ptr<frc::JoystickButton> shrinkHopperBtn;
	std::shared_ptr<frc::JoystickButton> keyShotBtn;
	std::shared_ptr<frc::JoystickButton> boilerShotBtn;
	std::shared_ptr<frc::JoystickButton> reverseShooterBtn;
	std::shared_ptr<frc::JoystickButton> driverKillEverythingBtn;
	std::shared_ptr<frc::JoystickButton> operatorKillEverythingBtn;
	std::shared_ptr<frc::JoystickButton> driverSwitchCamBtn;
	std::shared_ptr<frc::JoystickButton> driverRotateBtn;

public:
	OI();
	std::shared_ptr<frc::Joystick> getDriverController();
	std::shared_ptr<frc::Joystick> getOperatorController();
};

#endif  // OI_H
