#include "HoldButtonToTurnCmd.h"

HoldButtonToTurnCmd::HoldButtonToTurnCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires((Subsystem *) drivetrainSub.get());
}

// Called just before this Command runs the first time
void HoldButtonToTurnCmd::Initialize()
{
	drivetrainSub->driveSingle();
}

// Called repeatedly when this Command is scheduled to run
void HoldButtonToTurnCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool HoldButtonToTurnCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void HoldButtonToTurnCmd::End()
{
	drivetrainSub->driveStop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldButtonToTurnCmd::Interrupted()
{
	this->End();
}
