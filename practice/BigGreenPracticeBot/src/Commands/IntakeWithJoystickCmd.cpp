#include "IntakeWithJoystickCmd.h"

IntakeWithJoystickCmd::IntakeWithJoystickCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires((Subsystem *)(intakeSub.get()));
}

// Called just before this Command runs the first time
void IntakeWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeWithJoystickCmd::Execute()
{
	intakeSub->SetIntakeSpeed(oi->getAxisValue(INTAKE_CONTROL_CONTROLLER, INTAKE_CONTROL_AXIS));
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeWithJoystickCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeWithJoystickCmd::Interrupted()
{

}
