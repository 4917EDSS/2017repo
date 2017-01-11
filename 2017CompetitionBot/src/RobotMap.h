#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;
// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

// CAN IDs
constexpr int LEFT_DRIVE_MOTOR_CANID = 1;
constexpr int RIGHT_DRIVE_MOTOR_CANID = 2;
constexpr int TOP_SHOOTER_MOTOR_CANID = 3;
constexpr int BOTTOM_SHOOTER_MOTOR_CANID = 4;
constexpr int CLIMBER_MOTOR_CANID = 5;

#endif  // ROBOTMAP_H
