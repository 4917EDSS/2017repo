#include "LiftWithJoystickCmd.h"

LiftWithJoystickCmd::LiftWithJoystickCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires((Subsystem *)(liftSub.get()));
}

// Called just before this Command runs the first time
void LiftWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftWithJoystickCmd::Execute()
{
	liftSub->SetLiftSpeed(oi->getAxisValue(LIFT_CONTROL_CONTROLLER, LIFT_CONTROL_AXIS));
}

// Make this return true when this Command no longer needs to run execute()
bool LiftWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftWithJoystickCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftWithJoystickCmd::Interrupted()
{

}
