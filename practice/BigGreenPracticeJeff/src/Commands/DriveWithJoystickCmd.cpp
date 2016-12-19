#include <cmath>
#include "DriveWithJoystickCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	Requires(drivetrainSub.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCmd::Execute()
{
	float rightStick = oi->GetRightVer();
	float leftStick = oi->GetLeftVer();
	drivetrainSub->drive(rightStick, leftStick);


}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCmd::End()
{
	drivetrainSub->drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCmd::Interrupted()
{
	DriveWithJoystickCmd::End();
}
