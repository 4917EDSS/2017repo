#include "ShiftCmd.h"

ShiftCmd::ShiftCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShiftCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShiftCmd::Execute()
{
	if(drivetrainSub->getGear() == DrivetrainSub::ShiftState::HIGH){
			drivetrainSub->shift(DrivetrainSub::ShiftState::LOW);
		}
	else if(drivetrainSub->getGear() == DrivetrainSub::ShiftState::LOW){
		drivetrainSub->shift(DrivetrainSub::ShiftState::HIGH);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShiftCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftCmd::Interrupted()
{

}
