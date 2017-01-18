#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	motor.reset(new CANTalon(SHOOTER_MOTOR_CANID));
	motor->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	motor->Set(0);
	motorEnc.reset(new frc::Encoder(SHOOTER_MOTOR_ENC1_DIO, SHOOTER_MOTOR_ENC2_DIO));
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
