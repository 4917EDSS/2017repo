#include <Commands/ShootCmd.h>
#include "OI.h"

#include <WPILib.h>
#include "Commands/RunPickupCmd.h"
#include "Commands/LiftCmd.h"
#include "Commands/IncreaseSpeedCmd.h"
#include "Commands/DecreaseSpeedCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ToggleShifterCmd.h"
#include "Commands/DriveForwards.h"
#include "Commands/SetShooterSpeedCmd.h"
#include "Commands/ReverseShooterCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));
	operatorController.reset(new frc::Joystick(OPERATOR_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(operatorController.get(), OPERATOR_INTAKE_BTN));
	dIntakeBtn->WhileHeld(new RunPickupCmd());
	liftBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_LIFT_BTN));
	liftBtn->WhileHeld(new LiftCmd(1.0));
	lowerBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_LOWER_BTN));
	lowerBtn->WhileHeld(new LiftCmd(-1.0));
	shooterEnableBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_SHOOT_BTN));
	shooterEnableBtn->WhileHeld(new ShootCmd());
	increaseSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_INCREASE_SPEED_BTN));
	increaseSpeedBtn->WhenPressed(new IncreaseSpeedCmd());
	decreaseSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_DECREASE_SPEED_BTN));
	decreaseSpeedBtn->WhenPressed(new DecreaseSpeedCmd());
	setLowSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_SET_LOW_SPEED_BTN));
	setLowSpeedBtn->WhenPressed(new SetShooterSpeedCmd(-1770));
	setHighSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_SET_HIGH_SPEED_BTN));
	setHighSpeedBtn->WhenPressed(new SetShooterSpeedCmd(-2100));
	reverseShooterBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_REVERSE_SHOOTER_BTN));
	reverseShooterBtn->WhileHeld(new ReverseShooterCmd(300));

	shiftBtn.reset(new JoystickButton(driverController.get(), DRIVER_SHIFT_BTN));
	shiftBtn->WhenPressed(new ToggleShifterCmd());
	driveForwardsBtn.reset(new JoystickButton(driverController.get(), DRIVER_FORWARDS_BTN));
	driveForwardsBtn->WhileHeld(new DriveForwards());


}
std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
std::shared_ptr<frc::Joystick> OI::getOperatorController()
{

	   return operatorController;
}
