#include "StopDriveTrainCmd.h"

StopDriveTrainCmd::StopDriveTrainCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void StopDriveTrainCmd::Initialize()
{
	drivetrainSub->drive(0,0);
}

// Called repeatedly when this Command is scheduled to run
void StopDriveTrainCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopDriveTrainCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopDriveTrainCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopDriveTrainCmd::Interrupted()
{

}
