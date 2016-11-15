#include "ToggleJawsInOutCmd.h"

ToggleJawsInOutCmd::ToggleJawsInOutCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(liftSub.get());
}

// Called just before this Command runs the first time
void ToggleJawsInOutCmd::Initialize()
{
	liftSub->ToggleLocksInOut();
}

// Called repeatedly when this Command is scheduled to run
void ToggleJawsInOutCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleJawsInOutCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleJawsInOutCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleJawsInOutCmd::Interrupted()
{

}
