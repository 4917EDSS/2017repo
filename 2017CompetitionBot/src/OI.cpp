#include "OI.h"

#include <WPILib.h>
#include "Commands/RunPickupCmd.h"
#include "Commands/LiftCmd.h"
#include "Commands/ShootWhileHeldCmd.h"
#include "Commands/IncreaseSpeedCmd.h"
#include "Commands/DecreaseSpeedCmd.h"
#include "Commands/DriveTurnCmd.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(driverController.get(), DRIVER_INTAKE_BTN));
	dIntakeBtn->WhileHeld(new RunPickupCmd);
	liftBtn.reset(new JoystickButton(driverController.get(), DRIVER_LIFT_BTN));
	liftBtn->WhileHeld(new LiftCmd(1.0));
	lowerBtn.reset(new JoystickButton(driverController.get(), DRIVER_LOWER_BTN));
	lowerBtn->WhileHeld(new LiftCmd(-1.0));
	shooterEnableBtn.reset(new JoystickButton(driverController.get(), DRIVER_SHOOT_BTN));
	shooterEnableBtn->WhileHeld(new ShootWhileHeldCmd());
	increaseSpeedBtn.reset(new JoystickButton(driverController.get(), DRIVER_INCREASE_SPEED_BTN));
	increaseSpeedBtn->WhenPressed(new IncreaseSpeedCmd());
	decreaseSpeedBtn.reset(new JoystickButton(driverController.get(), DRIVER_DECREASE_SPEED_BTN));
	decreaseSpeedBtn->WhenPressed(new DecreaseSpeedCmd());
	driveTurnBtn.reset(new JoystickButton(driverController.get(), DRIVER_DRIVETURN_BTN));
	driveTurnBtn->WhenPressed(new DriveTurnCmd(60));
}
std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}
