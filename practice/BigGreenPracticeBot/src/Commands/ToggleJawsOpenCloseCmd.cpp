#include "ToggleJawsOpenCloseCmd.h"

ToggleJawsOpenCloseCmd::ToggleJawsOpenCloseCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires((Subsystem *)(liftSub.get()));
}

// Called just before this Command runs the first time
void ToggleJawsOpenCloseCmd::Initialize()
{
	liftSub->ToggleLocksOpenClosed();
}

// Called repeatedly when this Command is scheduled to run
void ToggleJawsOpenCloseCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleJawsOpenCloseCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleJawsOpenCloseCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleJawsOpenCloseCmd::Interrupted()
{

}
