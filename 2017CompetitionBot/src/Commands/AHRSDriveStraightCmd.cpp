#include "AHRSDriveStraightCmd.h"
#include "RobotMap.h"
#include <iostream>
#include <cmath>

AHRSDriveStraightCmd::AHRSDriveStraightCmd(int distance)
{
	targetDistance = distance;
	Requires(drivetrainSub.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

AHRSDriveStraightCmd::AHRSDriveStraightCmd(int distanceBlue, int distanceRed) {
	if(frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue) {
		targetDistance = distanceBlue;
	} else {
		targetDistance = distanceRed;
	}
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void AHRSDriveStraightCmd::Initialize()
{
	drivetrainSub->reset();
	drivetrainSub->EnableBalancerPID(0);
	drivetrainSub->EnableDistancePID(0.7, targetDistance);
	timeFromLastMove = 0;
	lastMoveTime = 0;
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
	if(fabs(drivetrainSub->getLeftEncoderSpeed()) < 40 and fabs(drivetrainSub->getRightEncoderSpeed()) < 40){
		timeFromLastMove = TimeSinceInitialized() - lastMoveTime;
	}
	else{
		lastMoveTime = TimeSinceInitialized();
	}
	if((fabs(drivetrainSub->getLeftEncoder()-targetDistance)<=DRIVE_DISTANCE_TOLERANCE and fabs(drivetrainSub->getLeftEncoderSpeed()) < DISTANCE_SPEED_TOLERANCE) or (timeFromLastMove > 1)){
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
