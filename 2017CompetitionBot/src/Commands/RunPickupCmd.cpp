#include "RunPickupCmd.h"
#include "OI.h"

RunPickupCmd::RunPickupCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intakeSub.get());
	Requires(shooterSub.get());
}

// Called just before this Command runs the first time
void RunPickupCmd::Initialize() {
	intakeSub->setPickupMotor(1.0);
	shooterSub->setFeeder1(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void RunPickupCmd::Execute() {
	std::shared_ptr<frc::Joystick> dCtrl = oi->getDriverController();
	if(abs(dCtrl->GetRawAxis(DRIVER_LEFT_TANK_DRIVE_AXIS)) < 0.01 && abs(dCtrl->GetRawAxis(DRIVER_RIGHT_TANK_DRIVE_AXIS)) < 0.01){
		intakeSub->setPickupMotor(0.0);
		shooterSub->setFeeder1(0.0);
	}
	else{
		intakeSub->setPickupMotor(1.0);
		shooterSub->setFeeder1(-1.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunPickupCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunPickupCmd::End() {
	intakeSub->setPickupMotor(0.00);
	shooterSub->setFeeder1(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunPickupCmd::Interrupted() {
	End();
}
