#include "DriveTurnCmd.h"
#include <math.h>

DriveTurnCmd::DriveTurnCmd(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
	turnDegrees = angle;
}
// Called just before this Command runs the first time
void DriveTurnCmd::Initialize() {
	printf( "Enabling turn %f\n", turnDegrees );
	drivetrainSub->resetAHRS();
	drivetrainSub->enableTurnPID(turnDegrees);
	lastCheckpoint = drivetrainSub->getYaw();
	lastCheckpointTime = TimeSinceInitialized();
}
#include <iostream>
// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute() {
	drivetrainSub->PIDTurn();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished() {
	std::cout << "AHRS: Yaw=" << drivetrainSub->getYaw() << " Chk=" << lastCheckpoint << std::endl;
	if (fabs(lastCheckpoint - drivetrainSub->getYaw()) > DRIVE_TURN_TOLERANCE){
		lastCheckpoint = drivetrainSub->getYaw();
		lastCheckpointTime = TimeSinceInitialized();
		return false;
	}
	else if ((TimeSinceInitialized() - lastCheckpointTime) > TURN_TOLERANCE_DURATION){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveTurnCmd::End() {
	drivetrainSub->disableTurnPID();
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted() {
	End();
}
