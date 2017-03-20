#include <math.h>
#include "Components/MachineVision.h"
#include "RotateToVisionCmd.h"

RotateToVisionCmd::RotateToVisionCmd(int minVisionTargets) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());

	turnDegrees = 0;
	minTargets = minVisionTargets;
	lastFrameTime = 0;
}

// Called just before this Command runs the first time
void RotateToVisionCmd::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void RotateToVisionCmd::Execute() {
	struct MachineVisionData mvd = visionResults.getResults();
	if(mvd.frameTime != lastFrameTime && mvd.numCountoursFound >= minTargets) {
		lastFrameTime = mvd.frameTime;

		double angle = ComputeDeviation();
		std::cout << "RotateToVisionCmd::angle :"<<angle<<std::endl;
	}
//	drivetrainSub->PIDTurn();
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToVisionCmd::IsFinished() {
//	if (fabs(drivetrainSub->getRate()) < DRIVE_RATE_TOLERANCE && fabs(drivetrainSub->getAngle() - turnDegrees) < DRIVE_TURN_TOLERANCE){
//		return true;
//	}
//	else {
		return false;
//	}
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

#define RADIANS(x) ((x) * PI / 180.0)
#define DEGREES(x) ((x) * 180.0 / PI)

double RotateToVisionCmd::ComputeDeviation() {
	struct MachineVisionData mvd = visionResults.getResults();
	double cameraMountingInclinationDegrees = 23.6;
	double targetRatio = (10.25 - 4.0) / 5.0 * cos(RADIANS(cameraMountingInclinationDegrees));		// from vision targets dimensions if camera is aligned with target want separation / height
	double ratio = mvd.averageHeight == 0 ? 1.0 : (double) mvd.horizontalSeparation / mvd.averageHeight;
	double cappedRatio = ratio / targetRatio;
	if(cappedRatio > 1.0) {
		printf("clipping %7.5f to 1.0\r\n",cappedRatio);
		cappedRatio = 1.0;
	}
	// angle is an approximation of how far off the normal we are from the target plane
	// when we are aligned with target then ratio should be target ratio, if 90 degrees off ratio will be zero.
	// determine which way to turn by relative size of the two targets, turn towards the smaller of the two.
	double deviationAngle = DEGREES(acos(cappedRatio) * 180.0 / PI)  * ((mvd.heightDifference > 0) ? -1 : 1);
	double bearingAngle = mvd.centerX * MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE / mvd.imageWidth;
	double delay = Timer::GetFPGATimestamp() - mvd.frameTimeSeconds;
	double distanceToTarget_mm = 5*25.4 / tan(RADIANS(mvd.averageHeight * MACHINE_VISION_CAMERA_VERTICAL_VIEW_ANGLE / mvd.imageHeight));

	printf("H:          FT,    FT(s),     PT,   delay,    D,    A, cX,  x, cY,  y, AH, DH, HS,    R,   CR,d(mm)\r\n"
			"D:%012lld,%8.3f,%7.5f,%7.5f,%5.2f,%5.2f,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%5.3f,%5.3f,%5.0f\r\n",
			mvd.frameTime,
			mvd.frameTimeSeconds,
			mvd.processingTime,
			delay,
			deviationAngle,
			bearingAngle,
			mvd.centerX,
			mvd.x,
			mvd.centerY,
			mvd.y,
			mvd.averageHeight,
			mvd.heightDifference,
			mvd.horizontalSeparation,
			ratio,
			cappedRatio,
			distanceToTarget_mm
			);
	std::cout << "RotateToVision: #deg=" << bearingAngle << " (cX=" << mvd.centerX << " imgW=" << mvd.imageWidth <<
			" camAngle=" <<	MACHINE_VISION_CAMERA_HORIZONTAL_VIEW_ANGLE << ")" << std::endl;
	std::cout << "Normal Estimation: #deg=" << deviationAngle << "(sep=" << mvd.horizontalSeparation
			<< ", height=" << mvd.averageHeight<< ", ratio=" << ratio << ")"
			<< std::endl;
	return bearingAngle;
}
