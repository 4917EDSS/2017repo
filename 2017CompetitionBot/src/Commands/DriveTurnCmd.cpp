#include "DriveTurnCmd.h"

DriveTurnCmd::DriveTurnCmd(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
	turnDegrees = angle;
}
#include <iostream>
// Called just before this Command runs the first time
void DriveTurnCmd::Initialize() {
	std::cerr << "initialized";
	drivetrainSub->resetAHRS();
	drivetrainSub->enableTurnPID(turnDegrees);
	lastCheckpoint = drivetrainSub->getYaw();
	lastCheckpointTime = TimeSinceInitialized();
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute() {
	drivetrainSub->PIDTurn();
	std::cout << "EXECUTING";
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished() {
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!DONE!!!!!!!!!!!!!!!!!!!!!!";
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
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted() {
	End();
}
