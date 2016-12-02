#include "DriveStraightCmd.h"

DriveStraightCmd::DriveStraightCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	drivetrainSub->drive(0.5, 0.5);
}
// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	drivetrainSub->drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	DriveStraightCmd::End();
}
