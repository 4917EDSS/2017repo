#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	targetSpeed = -2200;
	motor.reset(new CANTalon(SHOOTER_MOTOR_CANID));
	feederMotor1.reset(new CANTalon(FEEDER_MOTOR1_CANID));
	feederMotor2.reset(new CANTalon(FEEDER_MOTOR2_CANID));
	feederMotor1->Set(0);
	feederMotor2->Set(0);
	motor->Set(0);
	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Shooter", "Motor", motor);
	//lw->AddActuator("Shooter", "Bottom Motor", bottomMotor);
	// moved up to allow tuning
	motor->SetF(0.063);
	motor->SetP(3);
	motor->SetD(0.001);
}

void ShooterSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSub::update()
{
	motor->Set(targetSpeed);
	double currentSpeed = getSpeed();
	double error = fabs((currentSpeed - targetSpeed)/targetSpeed);
	if (error > 0.1) {
		setFeederSpeed(0.0);
	}
	else {
		setFeederSpeed(1.0);
	}
}
void ShooterSub::enableShooter()
{
	enableSpeedController();
}
void ShooterSub::disableShooter()
{
	disableSpeedController();
	motor->Set(0.0);
	setFeederSpeed(0.0);
}
void ShooterSub::increaseSpeed()
{
	targetSpeed -= 50.0;
}
void ShooterSub::decreaseSpeed()
{
	targetSpeed += 50.0;
}
#include <iostream>
double ShooterSub::getSpeed()
{
	return motor->GetEncVel()*60*10/4096; //Discovered from reading source code and playing with numbers
}
double ShooterSub::getTargetSpeed()
{
	return targetSpeed;
}
void ShooterSub::enableSpeedController(){
	motor->SetControlMode(frc::CANSpeedController::kSpeed);
	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor->SetSensorDirection(false);
	motor->ConfigNominalOutputVoltage(0., 0.);
	motor->ConfigPeakOutputVoltage(+12., -12.);
	motor->SelectProfileSlot(0);
}
void ShooterSub::disableSpeedController(){
	motor->SetControlMode(frc::CANSpeedController::kPercentVbus);
}

void ShooterSub::setFeederSpeed(float speed){
	feederMotor1->Set(speed);
	feederMotor2->Set(speed);
}
