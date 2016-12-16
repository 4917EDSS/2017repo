#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;
const int MOTOR1_CANID = 1;
const int MOTOR2_CANID = 2;
const int MOTOR1_ENC1_DIO = 0;
const int MOTOR1_ENC2_DIO = 1;
const int MOTOR2_ENC1_DIO = 2;
const int MOTOR2_ENC2_DIO = 3;
const int SHIFTER1_DIO = 5;
const int SHIFTER2_DIO = 6;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
