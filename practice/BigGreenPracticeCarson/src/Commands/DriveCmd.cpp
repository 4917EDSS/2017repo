#include "DriveCmd.h"
//#include "Subsystems/DrivetrainSub.h"

DriveCmd::DriveCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveCmd::Initialize()
{
	drivetrainSub->drive(1.0, 1.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCmd::Interrupted()
{

}
