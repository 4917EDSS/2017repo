#include "DriveWithJoystickCmd.h"
#include "OI.h"

DriveWithJoystickCmd::DriveWithJoystickCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainSub.get());
}

// Called just before this Command runs the first time
void DriveWithJoystickCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCmd::Execute() {
	std::shared_ptr<frc::Joystick> dCtrl = oi->getDriverController();
	drivetrainSub->drive(dCtrl->GetRawAxis(DRIVER_LEFT_TANK_DRIVE_AXIS),
						 dCtrl->GetRawAxis(DRIVER_RIGHT_TANK_DRIVE_AXIS));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCmd::Interrupted() {

}
