#include "DriveWithJoystickCmd.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires((Subsystem *)(drivetrainSub.get()));
}

// Called just before this Command runs the first time
void DriveWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCmd::Execute()
{
	drivetrainSub->SetDriveSpeed(
			oi->getAxisValue(TANKDRIVE_LEFT_CONTROLLER, TANKDRIVE_LEFT_AXIS),
			oi->getAxisValue(TANKDRIVE_RIGHT_CONTROLLER, TANKDRIVE_RIGHT_AXIS) );
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCmd::Interrupted()
{

}
