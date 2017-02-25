#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	targetSpeed = -2200;
	shooterMotor1.reset(new CANTalon(SHOOTER1_MOTOR_CANID));
	shooterMotor2.reset(new CANTalon(SHOOTER2_MOTOR_CANID));
	feederMotor1.reset(new CANTalon(FEEDER_MOTOR1_CANID));
	feederMotor2.reset(new CANTalon(FEEDER_MOTOR2_CANID));
	feederMotor1->Set(0);
	feederMotor2->Set(0);
	shooterMotor1->Set(0);
	shooterMotor2->SetControlMode(frc::CANSpeedController::kFollower);
	shooterMotor2->Set(SHOOTER1_MOTOR_CANID);
	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Shooter", "Motor", shooterMotor1);
	//lw->AddActuator("Shooter", "Bottom Motor", bottomMotor);
	// moved up to allow tuning
	shooterMotor1->SetF(0.4);
	shooterMotor1->SetP(0);
	shooterMotor1->SetD(5);

}

void ShooterSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSub::update()
{
	shooterMotor1->Set(targetSpeed);
	double currentSpeed = getSpeed();
	double error = fabs((currentSpeed - targetSpeed)/targetSpeed);
	if (targetSpeed > 0.0){
		setFeederSpeed(-1.0);
	}
	else if (error > 0.1) {
		setFeederSpeed(0.0);
	}
	else {
		setFeederSpeed(1.0);
	}
}
void ShooterSub::setShooterSpeed(float newSpeed)
{
	targetSpeed = newSpeed;
}
void ShooterSub::enableShooter()
{
	enableSpeedController();
}
void ShooterSub::disableShooter()
{
	disableSpeedController();
	shooterMotor1->Set(0.0);
	setFeederSpeed(0.0);
}
void ShooterSub::increaseSpeed()
{
	targetSpeed -= 10.0;
}
void ShooterSub::decreaseSpeed()
{
	targetSpeed += 10.0;
}
#include <iostream>
double ShooterSub::getSpeed()
{
	return shooterMotor1->GetEncVel()*60*10/4096; //Discovered from reading source code and playing with numbers
}
double ShooterSub::getTargetSpeed()
{
	return targetSpeed;
}
void ShooterSub::enableSpeedController(){
	shooterMotor1->SetControlMode(frc::CANSpeedController::kSpeed);
	shooterMotor1->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	shooterMotor1->SetSensorDirection(false);
	shooterMotor1->ConfigNominalOutputVoltage(0., 0.);
	shooterMotor1->ConfigPeakOutputVoltage(+12., -12.);
	shooterMotor1->SelectProfileSlot(0);
	shooterMotor1->SetVelocityMeasurementPeriod(CANTalon::Period_100Ms);
	shooterMotor1->SetVelocityMeasurementWindow(64);
}
void ShooterSub::disableSpeedController(){
	shooterMotor1->SetControlMode(frc::CANSpeedController::kPercentVbus);
}

void ShooterSub::setFeederSpeed(float speed){
	feederMotor1->Set(speed);
	feederMotor2->Set(speed);
}
