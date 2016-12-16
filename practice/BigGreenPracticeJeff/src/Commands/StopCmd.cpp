#include "StopCmd.h"

StopCmd::StopCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void StopCmd::Initialize()
{
	drivetrainSub->drive(0.0, 0.0);
}

// Called repeatedly when this Command is scheduled to run
void StopCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCmd::Interrupted()
{

}
