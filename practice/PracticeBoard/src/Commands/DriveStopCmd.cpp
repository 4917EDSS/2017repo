#include "DriveStopCmd.h"

DriveStopCmd::DriveStopCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires((Subsystem *)(drivetrainSub.get()));
}

// Called just before this Command runs the first time
void DriveStopCmd::Initialize()
{
	printf("Drive stop\n");
	drivetrainSub->driveStop();
}

// Called repeatedly when this Command is scheduled to run
void DriveStopCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStopCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveStopCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStopCmd::Interrupted()
{

}
