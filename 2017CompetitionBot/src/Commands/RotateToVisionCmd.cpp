#include <math.h>
#include "Components/MachineVision.h"
#include "RotateToVisionCmd.h"

RotateToVisionCmd::RotateToVisionCmd(int minVisionTargets) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());

	turnDegrees = 0;
	minTargets = minVisionTargets;
}

// Called just before this Command runs the first time
void RotateToVisionCmd::Initialize() {
	// Determine number of degrees needed to get the robot centered on the vision target
	struct MachineVisionData mvd = visionResults.getResults();

	if( mvd.numCountoursFound >= minTargets )
	{
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
		turnDegrees = (double)mvd.centerX / mvd.imageWidth * MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE/2;
		std::cout << "RotateToVision: #deg=" << turnDegrees << " (cX=" << mvd.centerX << " imgW=" << mvd.imageWidth <<
				" camAngle=" <<	MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE << ")" << std::endl;
		std::cout << "Normal Estimation: #deg=" << angle << "(sep=" << mvd.horizontalSeparation
				<< ", height=" << mvd.averageHeight<< ", ratio=" << ratio << ", deviation=" << angle << ")"
				<< std::endl;
	}
	else
	{
		// Can't see enough vision targets to determine correct turn angle
		// Command should terminate after first execute
		turnDegrees = 0.0;
	}
	drivetrainSub->resetAHRS();
	drivetrainSub->enableTurnPID(turnDegrees);
}

// Called repeatedly when this Command is scheduled to run
void RotateToVisionCmd::Execute() {
	drivetrainSub->PIDTurn();
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToVisionCmd::IsFinished() {
	if (fabs(drivetrainSub->getRate()) < DRIVE_RATE_TOLERANCE && fabs(drivetrainSub->getAngle() - turnDegrees) < DRIVE_TURN_TOLERANCE){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void RotateToVisionCmd::End() {
	drivetrainSub->disableTurnPID();
	drivetrainSub->drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToVisionCmd::Interrupted() {
	End();
}
