#include "DriveForwardCmd.h"

DriveForwardCmd::DriveForwardCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveForwardCmd::Initialize()
{
	drivetrainSub->drive(0.5, 0.5);
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveForwardCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardCmd::Interrupted()
{

}
