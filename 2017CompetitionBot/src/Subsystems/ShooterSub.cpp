#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	targetSpeed = -2400;
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
}

void ShooterSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSub::setSpeed()
{
	motor->Set(targetSpeed);
}
void ShooterSub::disableShooter()
{
	motor->Set(0.0);
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
	motor->SetF(0.056);
	motor->SetP(0.001);
	motor->SetD(8);
}
void ShooterSub::disableSpeedController(){
	motor->SetControlMode(frc::CANSpeedController::kPercentVbus);
}

void ShooterSub::setFeederSpeed(float speed){
	feederMotor1->Set(speed);
	feederMotor2->Set(speed);
}
