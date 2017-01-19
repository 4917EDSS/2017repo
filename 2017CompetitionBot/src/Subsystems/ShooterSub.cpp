#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	motor.reset(new CANTalon(SHOOTER_MOTOR_CANID));
	motor->SetControlMode(frc::CANSpeedController::kSpeed);
	motor->Set(0);
	motorEnc.reset(new frc::Encoder(SHOOTER_MOTOR_ENC1_DIO, SHOOTER_MOTOR_ENC2_DIO));
	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	motor->SetSensorDirection(false);
	motor->ConfigNominalOutputVoltage(0., 0.);
	motor->ConfigPeakOutputVoltage(+12., -12.);
	motor->SelectProfileSlot(0);
	motor->SetF(0.1);
	motor->SetP(0.1);
	motor->SetI(0.001);
	motor->SetD(0.000001);
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
void ShooterSub::setShooterSpeed(double speed)
{
	motor->Set(speed);
	//bottomMotor->Set(bSpeed);
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
