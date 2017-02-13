#include <Commands/ShootCmd.h>
#include "OI.h"

#include <WPILib.h>
#include "Commands/RunPickupCmd.h"
#include "Commands/LiftCmd.h"
#include "Commands/IncreaseSpeedCmd.h"
#include "Commands/DecreaseSpeedCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ToggleShifterCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));
	operatorController.reset(new frc::Joystick(OPERATOR_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(operatorController.get(), DRIVER_INTAKE_BTN));
	dIntakeBtn->WhileHeld(new RunPickupCmd());
	liftBtn.reset(new JoystickButton(operatorController.get(), DRIVER_LIFT_BTN));
	liftBtn->WhileHeld(new LiftCmd(1.0));
	lowerBtn.reset(new JoystickButton(operatorController.get(), DRIVER_LOWER_BTN));
	lowerBtn->WhileHeld(new LiftCmd(-1.0));
	shooterEnableBtn.reset(new JoystickButton(operatorController.get(), DRIVER_SHOOT_BTN));
	shooterEnableBtn->WhileHeld(new ShootCmd());
	increaseSpeedBtn.reset(new JoystickButton(operatorController.get(), DRIVER_INCREASE_SPEED_BTN));
	increaseSpeedBtn->WhenPressed(new IncreaseSpeedCmd());
	decreaseSpeedBtn.reset(new JoystickButton(operatorController.get(), DRIVER_DECREASE_SPEED_BTN));
	decreaseSpeedBtn->WhenPressed(new DecreaseSpeedCmd());
	shiftBtn.reset(new JoystickButton(driverController.get(), DRIVER_SHIFT_BTN));
	shiftBtn->WhenPressed(new ToggleShifterCmd());

}
std::shared_ptr<frc::Joystick> OI::getDriverController()
std::shared_ptr<frc::Joystick> OI::getOperatorController()
{
   return driverController;
   return operatorController;
}
