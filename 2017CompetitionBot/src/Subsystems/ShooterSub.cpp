#include "ShooterSub.h"
#include "../RobotMap.h"

ShooterSub::ShooterSub() : Subsystem("ShooterSub") {
	topMotor.reset(new CANTalon(TOP_SHOOTER_MOTOR_CANID));
	bottomMotor.reset(new CANTalon(BOTTOM_SHOOTER_MOTOR_CANID));

	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Shooter", "Top Motor", topMotor);
	lw->AddActuator("Shooter", "Bottom Motor", bottomMotor);
}

void ShooterSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSub::setShooterSpeed(double tSpeed, double bSpeed)
{
	topMotor->Set(tSpeed);
	bottomMotor->Set(bSpeed);
}
