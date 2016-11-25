#include "IntakeSub.h"
#include "../RobotMap.h"
#include "Commands/IntakeWithJoystickCmd.h"

IntakeSub::IntakeSub() :
		Subsystem("IntakeSub")
{
	leftMotor.reset(new CANTalon(LEFT_INTAKE_MOTOR_CANID));
	rightMotor.reset(new CANTalon(RIGHT_INTAKE_MOTOR_CANID));
	beltArmsOpenCloseActuator.reset(new Solenoid(INTAKE_ARMS_OPENCLOSE_SOLENOID_PCM_CHAN));
	rearLimitSwitch.reset(new DigitalInput(INTAKE_LIMIT_SWITCH_DIO));

	// Make the hardware available to be controlled in Test mode
	LiveWindow::GetInstance()->AddActuator("Intake", "leftMotor", leftMotor.get());
	LiveWindow::GetInstance()->AddActuator("Intake", "rightMotor", rightMotor.get());
	LiveWindow::GetInstance()->AddActuator("Intake", "beltArmsOpenCloseActuator", beltArmsOpenCloseActuator.get());
	LiveWindow::GetInstance()->AddSensor("Intake", "rearLimitSwitch", rearLimitSwitch.get());
}

void IntakeSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new IntakeWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void IntakeSub::SetIntakeSpeed(float speed)
{
	leftMotor->Set(speed);
	rightMotor->Set(speed);
}

void IntakeSub::SetArmsOpenClose(bool open)
{
	beltArmsOpenCloseActuator->Set(open);
}

void IntakeSub::ToggleArmsOpenClose()
{
	beltArmsOpenCloseActuator->Set(!beltArmsOpenCloseActuator->Get());
}

bool IntakeSub::IsRearLimitSwitchHit()
{
	return rearLimitSwitch->Get();
}
