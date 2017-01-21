#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	Preferences *prefs = Preferences::GetInstance();
	targetSpeed = prefs->GetDouble("SetShooterSpeed", 0.0);
	motor.reset(new CANTalon(SHOOTER_MOTOR_CANID));
	motor->SetControlMode(frc::CANSpeedController::kSpeed);
	motor->Set(0);
	motorEnc.reset(new frc::Encoder(SHOOTER_MOTOR_ENC1_DIO, SHOOTER_MOTOR_ENC2_DIO));
	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor->SetSensorDirection(false);
	motor->ConfigNominalOutputVoltage(0., 0.);
	motor->ConfigPeakOutputVoltage(+12., -12.);
	motor->SelectProfileSlot(0);
	motor->SetF(0.055);
	motor->SetP(0.1);
	motor->SetD(10);
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
void ShooterSub::updateShooter()
{
	motor->Set(targetSpeed);
	//bottomMotor->Set(bSpeed);
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
int ShooterSub::getEncoder()
{
	return motorEnc->GetRaw();
}
void ShooterSub::resetEncoder(){
	motorEnc->Reset();
}
double ShooterSub::getSpeed()
{
	return motor->GetSpeed();
}
double ShooterSub::getTargetSpeed()
{
	return targetSpeed;
}
void ShooterSub::enableSpeedController(){
	motor->SetControlMode(frc::CANSpeedController::kSpeed);
}
void ShooterSub::disableSpeedController(){
	motor->SetControlMode(frc::CANSpeedController::kPercentVbus);
}

