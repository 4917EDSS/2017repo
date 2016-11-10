#include "LiftSub.h"
#include "../RobotMap.h"

LiftSub::LiftSub() :
		Subsystem("LiftSub")
{
	liftMotor.reset(new CANTalon(LIFT_MOTOR_CANID));
	//liftMotorEncoder.reset(new Encoder());
	lockOpenCloseActuator.reset(new Solenoid(LOCKS_OPENCLOSE_SOLENOID_PCM_CHAN));
	lockInOutActuator.reset(new Solenoid(LOCKS_INOUT_SOLENOID_PCM_CHAN));
	topLimitSwitch.reset(new DigitalInput(LIFT_BOTTOM_LIMIT_SWITCH_DIO));
	//bottomLimitSwitch.reset(new DigitalInput());

	// Make the hardware available to be controlled in Test mode
	LiveWindow::GetInstance()->AddActuator("Lift", "LiftMotor", (CANTalon *)(liftMotor.get()));
	LiveWindow::GetInstance()->AddActuator("Lift", "lockOpenCloseActuators", (Solenoid *)(lockOpenCloseActuator.get()));
	LiveWindow::GetInstance()->AddActuator("Lift", "lockInOutActuators", (Solenoid *)(lockInOutActuator.get()));
	LiveWindow::GetInstance()->AddSensor("Lift", "topLimitSwitch", (DigitalInput *)(topLimitSwitch.get()));

}

void LiftSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void LiftSub::SetLiftSpeed(float speed)
{
	liftMotor->Set(speed);
}

void LiftSub::SetLocksOpenClosed(bool open)
{
	lockOpenCloseActuator->Set(open);
}

void LiftSub::ToggleLocksOpenClosed()
{
	lockOpenCloseActuator->Set(!lockOpenCloseActuator->Get());
}

void LiftSub::SetLockInOut(bool in)
{
	lockInOutActuator->Set(in);
}

void LiftSub::ToggleLocksInOut()
{
	lockInOutActuator->Set(!lockInOutActuator->Get());
}

bool LiftSub::IsTopLimitSwitchHit()
{
	return topLimitSwitch->Get();
}
