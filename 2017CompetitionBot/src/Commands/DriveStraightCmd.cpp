#include "DriveStraightCmd.h"

DriveStraightCmd::DriveStraightCmd(int distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
	endDistance = distance;
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize() {
	leftSpeed=0.5;
	rightSpeed=0.5;

	drivetrainSub->drive(leftSpeed,rightSpeed);
	drivetrainSub->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute() {
	if(drivetrainSub->getLeftEncoder()>drivetrainSub->getRightEncoder()+100){
		if(rightSpeed==0.5){
			leftSpeed=leftSpeed-0.05;
		}
		else{
			rightSpeed=0.5;
		}
	}
	else if(drivetrainSub->getRightEncoder()>drivetrainSub->getLeftEncoder()+100){
		if(leftSpeed==0.5){
			rightSpeed=rightSpeed-0.05;
		}
		else{
			leftSpeed=0.5;
		}
	}
	else{
		leftSpeed=0.5;
		rightSpeed=0.5;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished() {
	if(drivetrainSub->getRightEncoder()>endDistance){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void DriveStraightCmd::End() {
	drivetrainSub->drive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted() {
	End();
}
