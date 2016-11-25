#include "ToggleShifterCmd.h"

ToggleShifterCmd::ToggleShifterCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void ToggleShifterCmd::Initialize()
{
	drivetrainSub->ToggleDriveShifter();
}

// Called repeatedly when this Command is scheduled to run
void ToggleShifterCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleShifterCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleShifterCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleShifterCmd::Interrupted()
{

}
