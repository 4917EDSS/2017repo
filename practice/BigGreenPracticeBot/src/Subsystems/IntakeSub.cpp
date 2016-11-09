#include "IntakeSub.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub() :
		Subsystem("IntakeSub")
{
	leftMotor.reset(new CANTalon(LEFT_INTAKE_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_INTAKE_MOTOR_CANID));
	beltArmsOpenCloseActuator.reset(new DoubleSolenoid(INTAKE_OPENCLOSE_DBLSOLENOID1_PCM_CHAN, INTAKE_OPENCLOSE_DBLSOLENOID2_PCM_CHAN));
	rearLimitSwitch.reset(new DigitalInput(INTAKE_LIMIT_SWITCH_DIO));
}

void IntakeSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
