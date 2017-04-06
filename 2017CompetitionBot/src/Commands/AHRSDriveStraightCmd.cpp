#include "AHRSDriveStraightCmd.h"
#include "RobotMap.h"
#include <iostream>
#include <cmath>

AHRSDriveStraightCmd::AHRSDriveStraightCmd(int distance, float speed)
{
	targetSpeed = speed;
	targetDistance = distance;
	Requires(drivetrainSub.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AHRSDriveStraightCmd::Initialize()
{
	drivetrainSub->reset();
	drivetrainSub->EnableBalancerPID(0);
	drivetrainSub->EnableDistancePID(targetSpeed, targetDistance);
}

// Called repeatedly when this Command is scheduled to run
void AHRSDriveStraightCmd::Execute()
{
	drivetrainSub->PIDDrive();
}

// Make this return true when this Command no longer needs to run execute()
bool AHRSDriveStraightCmd::IsFinished()
{
	//if distance and speed are in tolerance
	if(fabs(drivetrainSub->getLeftEncoder()-targetDistance)<=DRIVE_DISTANCE_TOLERANCE and fabs(drivetrainSub->getLeftEncoderSpeed()) < DISTANCE_SPEED_TOLERANCE){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void AHRSDriveStraightCmd::End()
{
	drivetrainSub->DisableBalancerPID();
	drivetrainSub->DisableDistancePID();
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AHRSDriveStraightCmd::Interrupted()
{
	End();
}
