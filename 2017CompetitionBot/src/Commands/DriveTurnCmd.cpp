#include "DriveTurnCmd.h"
#include <math.h>
#include <iostream>

DriveTurnCmd::DriveTurnCmd(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
	turnDegrees = angle;
}
// Called just before this Command runs the first time
void DriveTurnCmd::Initialize() {
	// Hack for turn-to-vision command
	std::cout << "DriveTurnCmd" << std::endl;
	if( 1) {//turnDegrees < -999999.0 ) {
		struct MachineVisionData mvd = visionResults.getResults();
		double targetRatio = (10.25 - 4.0) / 5.0;		// from vision targets dimensions if camera is aligned with target want separation / height
		double ratio = mvd.averageHeight == 0 ? 1.0 : (double) mvd.horizontalSeparation / mvd.averageHeight;
		double cappedRatio = ratio / targetRatio;
		if(cappedRatio > 1.0) {
			cappedRatio = 1.0;
		}
		// angle is an approximation of how far off the normal we are from the target plane
		// when we are aligned with target then ratio should be target ratio, if 90 degrees off ratio will be zero.
		// determine which way to turn by relative size of the two targets, turn towards the smaller of the two.
		double angle = acos(cappedRatio) * ((mvd.heightDifference > 0) ? -1 : 1);

		std::cout << "X,W,VA,H,HS,HS/H,HD,D=" << mvd.centerX << ","
				<< mvd.imageWidth << ","
				<< MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE << ","
				<< mvd.averageHeight << ","
				<< mvd.horizontalSeparation << ","
				<< ratio << ","
				<< mvd.heightDifference << ","
				<< angle << ","
				<< std::endl;
		turnDegrees = (double)mvd.centerX / mvd.imageWidth * MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE/2 + angle;
		std::cout << "Turning " << turnDegrees << std::endl;
	}

	else if (drivetrainSub->getAlliance() == RED) {
		turnDegrees = -turnDegrees;
	}
	printf( "Enabling turn %f\n", turnDegrees );
	drivetrainSub->resetAHRS();
	drivetrainSub->enableTurnPID(turnDegrees);
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute() {
	drivetrainSub->PIDTurn();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished() {
	if (fabs(drivetrainSub->getRate()) < DRIVE_RATE_TOLERANCE && fabs(drivetrainSub->getAngle() - turnDegrees) < DRIVE_TURN_TOLERANCE){
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
