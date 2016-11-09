#include "LiftSub.h"
#include "../RobotMap.h"

LiftSub::LiftSub() :
		Subsystem("LiftSub")
{
	liftMotor.reset(new CANTalon(LIFT_MOTOR_CANID));
	//liftMotorEncoder.reset(new Encoder());
	lockOpenCloseActuators.reset(new DoubleSolenoid(LOCKS_OPENCLOSE_DBLSOLENOID1_PCM_CHAN, LOCKS_OPENCLOSE_DBLSOLENOID2_PCM_CHAN));
	lockInOutActuators.reset(new DoubleSolenoid(LOCKS_INOUT_DBLSOLENOID1_PCM_CHAN, LOCKS_INOUT_DBLSOLENOID2_PCM_CHAN));
	topLimitSwitch.reset(new DigitalInput(LIFT_BOTTOM_LIMIT_SWITCH_DIO));
	//bottomLimitSwitch.reset(new DigitalInput());
}

void LiftSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
