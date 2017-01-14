#include "DriveStraightCmd.h"

DriveStraightCmd::DriveStraightCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());

}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize() {
	leftSpeed=1.0;
	rightSpeed=1.0;
	drivetrainSub->drive(leftSpeed,rightSpeed);
	drivetrainSub->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute() {
	if(drivetrainSub->getLeftEncoder()>drivetrainSub->getRightEncoder()+100){
		if(rightSpeed==1.0){
			leftSpeed=leftSpeed-0.05;
		}
		else{
			rightSpeed=1.0;
		}
	}
	else if(drivetrainSub->getRightEncoder()>drivetrainSub->getLeftEncoder()+100){
		if(leftSpeed==1.0){
			rightSpeed=rightSpeed-0.05;
		}
		else{
			leftSpeed=1.0;
		}
	}
	else{
		leftSpeed=1.0;
		rightSpeed=1.0;
	}
	drivetrainSub->drive(leftSpeed,rightSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished() {
	if(drivetrainSub->getRightEncoder()>1000){
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
