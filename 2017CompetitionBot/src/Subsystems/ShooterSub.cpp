#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	preShotSpeedBoost = 0;
	preShotPrimed = false;
	preShotTimerRunning = false;

	targetSpeed = -2100;
	adjustmentSpeed = 0;
	shooterMotor1.reset(new CANTalon(SHOOTER1_MOTOR_CANID));
	feederMotor1.reset(new CANTalon(FEEDER_MOTOR1_CANID));
	feederMotor2.reset(new CANTalon(FEEDER_MOTOR2_CANID));
	feederMotor1->Set(0);
	feederMotor2->Set(0);
	shooterMotor1->Set(0);
	// TODO UNDO THIS AS SOON AS DRIVE TALON FIXED
	shooterMotor2.reset(new CANTalon(SHOOTER2_MOTOR_CANID));
	shooterMotor2->SetControlMode(frc::CANSpeedController::kFollower);
	shooterMotor2->Set(SHOOTER1_MOTOR_CANID);


	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Shooter", "Shooter Motor", shooterMotor1);
	lw->AddActuator("Shooter", "Shooter Motor 2", shooterMotor2);
	lw->AddActuator("Shooter", "Feeder Motor 1", feederMotor1);
	lw->AddActuator("Shooter", "Feeder Motor 2", feederMotor2);

	//lw->AddActuator("Shooter", "Bottom Motor", bottomMotor);
	// moved up to allow tuning
	shooterMotor1->SetF(0.045);
	shooterMotor1->SetP(0.4);
	shooterMotor1->SetD(1);

	feederMotor1->SetF(0.128);
	feederMotor1->SetP(0.26);
	feederMotor1->SetI(0.0002);
	feederMotor1->SetD(6.6);


}

void ShooterSub::resetPreShot() {
	preShotSpeedBoost = PRE_SHOT_SPEED_BOOST;
	preShotPrimed = true;
	preShotTimerRunning = false;
}

void ShooterSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSub::update(bool shooting)
{
	double setSpeed = targetSpeed + adjustmentSpeed + preShotSpeedBoost;
	shooterMotor1->Set(setSpeed);
	if(shooting){
		double currentSpeed = getSpeed();
		double error = fabs((currentSpeed - setSpeed)/setSpeed);
		if (setSpeed > 0.0){
			setFeederSpeed(-1.0);
		}
		else if (error < 0.05) {
			setFeederSpeed(1.0);
			if(preShotPrimed) {
				//Set end time 1 second later
				preShotEndTime = frc::Timer::GetFPGATimestamp() + 1e6;
				preShotPrimed = false;
				preShotTimerRunning = true;
			}
		}
	}
	else{
		setFeederSpeed(0.0);
	}

	if(preShotTimerRunning) {
		if(frc::Timer::GetFPGATimestamp() > preShotEndTime) {
			preShotTimerRunning = false;
			preShotSpeedBoost = 0;
		}
	}
}
void ShooterSub::setShooterSpeed(float newSpeed)
{
	targetSpeed = newSpeed;
}
void ShooterSub::enableShooter()
{
	enableSpeedController();
	resetPreShot();
}
void ShooterSub::disableShooter()
{
	disableSpeedController();
	shooterMotor1->Set(0.0);
	setFeederSpeed(0.0);
}
void ShooterSub::increaseSpeed()
{
	adjustmentSpeed -= 10.0;
}
void ShooterSub::decreaseSpeed()
{
	adjustmentSpeed += 10.0;
}
#include <iostream>
double ShooterSub::getSpeed()
{
	return shooterMotor1->GetEncVel()*60*10/4096; //Discovered from reading source code and playing with numbers
}
double ShooterSub::getTargetSpeed()
{
	return targetSpeed + adjustmentSpeed + preShotSpeedBoost;
}
double ShooterSub::getFeederSpeed() {
	return feederMotor1->GetSpeed();
}
void ShooterSub::enableSpeedController(){
	shooterMotor1->SetControlMode(frc::CANSpeedController::kSpeed);
	shooterMotor1->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	shooterMotor1->SetSensorDirection(false);
	shooterMotor1->ConfigNominalOutputVoltage(0., 0.);
	shooterMotor1->ConfigPeakOutputVoltage(+12., -12.);
	shooterMotor1->SelectProfileSlot(0);
	shooterMotor1->SetVelocityMeasurementPeriod(CANTalon::Period_5Ms);
	shooterMotor1->SetVelocityMeasurementWindow(50);

	feederMotor1->SetControlMode(frc::CANSpeedController::kSpeed);
	feederMotor1->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	feederMotor1->SetSensorDirection(false);
	feederMotor1->ConfigNominalOutputVoltage(0, 0);
	feederMotor1->ConfigPeakOutputVoltage(+12., -12.);
	feederMotor1->SelectProfileSlot(0);
}
void ShooterSub::disableSpeedController(){
	shooterMotor1->SetControlMode(frc::CANSpeedController::kPercentVbus);
	feederMotor1->SetControlMode(frc::CANSpeedController::kPercentVbus);
}

void ShooterSub::setFeederSpeed(float speed){
	feederMotor1->Set(speed * 5500);
	feederMotor2->Set(speed);
}

void ShooterSub::setFeeder1(float speed){
	feederMotor2->Set(speed);
}
