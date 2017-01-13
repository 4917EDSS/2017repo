#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// CAN Bus Devices
const int LEFT_DRIVE_MOTOR_CANID = 10;
const int LEFT2_DRIVE_MOTOR_CANID = 1;
const int RIGHT_DRIVE_MOTOR_CANID = 3;
const int RIGHT2_DRIVE_MOTOR_CANID = 2;
const int LIFT_MOTOR_CANID = 8;				// Includes encoder
const int LIFT2_MOTOR_CANID = 9;
const int LEFT_INTAKE_MOTOR_CANID = 5;
const int RIGHT_INTAKE_MOTOR_CANID = 7;


// PWM Outputs (0..9)


// Pneumatic Control Module Outputs (0..7)
const int DRIVE_SHIFTER_SOLENOID_PCM_CHAN = 0;	// Not used in Big Green but needed for practice board
const int INTAKE_ARMS_OPENCLOSE_SOLENOID_PCM_CHAN = 1;
const int LOCKS_OPENCLOSE_SOLENOID_PCM_CHAN = 2;
const int LOCKS_INOUT_SOLENOID_PCM_CHAN = 3;


// Digital inputs/outputs (0..9)
const int INTAKE_LIMIT_SWITCH_DIO = 5;
const int LIFT_BOTTOM_LIMIT_SWITCH_DIO = 4;
//const int LIFT_TOP_LIMIT_SWITCH_DIO = ?;
const int LEFT_DRIVE_MOTOR_ENCODER1_DIO = 0;
const int LEFT_DRIVE_MOTOR_ENCODER2_DIO = 1;
const int RIGHT_DRIVE_MOTOR_ENCODER1_DIO = 2;
const int RIGHT_DRIVE_MOTOR_ENCODER2_DIO = 3;

// Analog inputs (0..3)



#endif
