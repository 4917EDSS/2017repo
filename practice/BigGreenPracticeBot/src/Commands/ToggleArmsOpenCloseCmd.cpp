#include "ToggleArmsOpenCloseCmd.h"

ToggleArmsOpenCloseCmd::ToggleArmsOpenCloseCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(intakeSub.get());
}

// Called just before this Command runs the first time
void ToggleArmsOpenCloseCmd::Initialize()
{
	intakeSub->ToggleArmsOpenClose();
}

// Called repeatedly when this Command is scheduled to run
void ToggleArmsOpenCloseCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleArmsOpenCloseCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleArmsOpenCloseCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleArmsOpenCloseCmd::Interrupted()
{

}
