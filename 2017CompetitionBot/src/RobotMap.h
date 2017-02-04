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

enum Alliance {
	RED,
	BLUE
};

//AHRS define
#define AHRSInterface SPI::kMXP


// CAN IDs
constexpr int LEFT1_DRIVE_MOTOR_CANID = 10;
constexpr int LEFT2_DRIVE_MOTOR_CANID = 1;
constexpr int RIGHT1_DRIVE_MOTOR_CANID = 2;
constexpr int RIGHT2_DRIVE_MOTOR_CANID = 3;
constexpr int SHOOTER_MOTOR_CANID = 4;
constexpr int LIFT_MOTOR_CANID = 9; //switched this for shooter test, should be 7
constexpr int PICKUP_MOTOR_CANID = 5;
constexpr int FEEDER_MOTOR1_CANID = 8;
constexpr int FEEDER_MOTOR2_CANID = 6;
//constexpr int AGITATOR_MOTOR_CANID = 7;
//constexpr int CLIMBER_MOTOR_CANID = 8;
//constexpr int UNUSED_MOTOR_CANID = 9;

//DIO IDs
constexpr int LEFT_MOTOR_ENC1_DIO = 0;
constexpr int LEFT_MOTOR_ENC2_DIO = 1;
constexpr int RIGHT_MOTOR_ENC1_DIO = 2;
constexpr int RIGHT_MOTOR_ENC2_DIO = 3;
constexpr int SHOOTER_MOTOR_ENC1_DIO = 4;
constexpr int SHOOTER_MOTOR_ENC2_DIO = 5;

// Pneumatic control module outputs
constexpr int SHIFTER_PCM_ID1 = 0;
constexpr int SHIFTER_PCM_ID2 = 1;

//Auto Enc Distances
constexpr int LOAD_STRAIGHT_DIST = 5000;
constexpr int SHOOTING_DRIVE_DISTANCE = -269;
constexpr int SHOOTING_TURN_ANGLE = 50;
constexpr int BOILER_HOPPER_DISTANCE = 1994;
constexpr int ANGLE_AT_HOPPER = -90;
constexpr int BACK_INTO_HOPPER = 533;
constexpr int HOPPER_WAIT_TIME = 2;
constexpr int GEAR_WAIT_TIME = 2;
constexpr int DRIVE_AWAY_FROM_HOPPER = 0;
constexpr int TURN_TOWARDS_BOILER = 0;
constexpr int DRIVE_TOWARDS_BOILER = 0;
constexpr int ANGLE_OF_BOILER = 0;

//PID Values
constexpr int DRIVE_TURN_P = 0.045;
constexpr int DRIVE_TURN_I = 0;
constexpr int DRIVE_TURN_D = 0.09;
constexpr int DRIVE_TURN_TOLERANCE = 1;
constexpr int TURN_TOLERANCE_DURATION_S = 1;

// Axis Camera
#define AXIS_ADDRESS "10.49.17.11"
constexpr int AXIS_VISION_TARGETS_EXPOSURE_VALUE = 16;
constexpr int AXIS_VISION_RESOLUTION_WIDTH = 320;
constexpr int AXIS_VISION_RESOLUTION_HEIGHT = 240;
constexpr int AXIS_STREAM_RESOLUTION_WIDTH = 320;
constexpr int AXIS_STREAM_RESOLUTION_HEIGHT = 240;

#endif  // ROBOTMAP_H
