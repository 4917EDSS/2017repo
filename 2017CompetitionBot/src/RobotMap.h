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

// Auto values
constexpr float HOPPER_WAIT_TIME = 1.0;

//AHRS define
#define AHRSInterface SPI::kMXP


// CAN IDs
constexpr int LEFT1_DRIVE_MOTOR_CANID = 1;
constexpr int LEFT2_DRIVE_MOTOR_CANID = 3;
constexpr int RIGHT1_DRIVE_MOTOR_CANID = 0;
constexpr int RIGHT2_DRIVE_MOTOR_CANID = 8;
constexpr int SHOOTER_MOTOR_CANID = 2;
constexpr int LIFT_MOTOR_CANID = 4;
constexpr int INTAKE_MOTOR_CANID = 7;
constexpr int FEEDER_MOTOR1_CANID = 5;
constexpr int FEEDER_MOTOR2_CANID = 9;

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

// Drivetrain values
constexpr float DRIVETRAIN_DIS_PER_PULSE = 2000.0/2621.0;
constexpr int ENCODER_CONVERSION_FACTOR = 4;

//Auto Enc Distances
//1 m = 1318 encoder ticks
//1 encoder tick = 1.32 mm
constexpr int LOAD_STRAIGHT_DIST = 1886;
constexpr int CENTER_TO_BOILER = 2224;
constexpr int TURN_TO_BOILER_DEGREE = -119;
constexpr int BACK_OFF_OF_SHAFT_DIST = -301;
constexpr int GEAR_WAIT_TIME = 2;
constexpr int LOADER_SIDE_APPROACH_DIST = 1353;
constexpr int TURN_TO_LOADER_SIDE_SHAFT = -45;
constexpr int DRIVE_TO_LOADER_SIDE_SHAFT = 2500;
constexpr int SHOOTING_DRIVE_DISTANCE = -269;
constexpr int SHOOTING_TURN_ANGLE = 50;
constexpr int BOILER_HOPPER_DISTANCE = 1994;
constexpr int ANGLE_AT_HOPPER = -90;
constexpr int BACK_INTO_HOPPER = 533;
constexpr int DRIVE_AWAY_FROM_HOPPER = 100;
constexpr int TURN_TOWARDS_BOILER = 0;
constexpr int DRIVE_TOWARDS_BOILER = 0;
constexpr int ANGLE_OF_BOILER = 0;
constexpr int LOADER_SHAFT_TO_BOILER_ANGLE = -70;
constexpr int LOADER_SHAFT_TO_BOILER_DIST = 3000;

//PID Values
constexpr float DRIVE_TURN_P = 0.045;
constexpr float DRIVE_TURN_I = 0;
constexpr float DRIVE_TURN_D = 0.09;
constexpr float DRIVE_TURN_TOLERANCE = 1;
constexpr float TURN_TOLERANCE_DURATION_S = 1;

// Axis Camera
#define AXIS_ADDRESS "10.49.17.11"
constexpr int AXIS_VISION_TARGETS_EXPOSURE_VALUE = 16;
constexpr int AXIS_VISION_RESOLUTION_WIDTH = 320;
constexpr int AXIS_VISION_RESOLUTION_HEIGHT = 240;
constexpr int AXIS_STREAM_RESOLUTION_WIDTH = 320;
constexpr int AXIS_STREAM_RESOLUTION_HEIGHT = 240;

// Robot info required by SilkyMotionManager - all in millimeters, seconds
constexpr double MAX_ACCEL = 1474; // mm/s^2
constexpr double MAX_DECEL = 4000; // mm/s^2
constexpr double MAX_VEL = 2800; // mm/s
constexpr double STOPPING_DISTANCE_TOLERANCE = 30; // mm
constexpr double STOPPING_SPEED_TOLERANCE = 10; // mm/s
constexpr double SILKY_KV = (1.0/MAX_VEL)*0.86;
constexpr double SILKY_KA = (1.0/MAX_DECEL)*0.485;
constexpr double SILKY_KP = 0.027;
constexpr double SILKY_KI = 0.00001;
constexpr double SILKY_KD = 0.00001;

//camera
constexpr double CENTER_X = 200;
constexpr double CAMERA_CENTER_TOLERANCE = 5;
constexpr double CENTER_CAMERA_SPEED_DIF = 0.2;


#endif  // ROBOTMAP_H
