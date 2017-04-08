#include <Commands/ExpandHopperCmd.h>
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
#include "Commands/OpenGearFlapsCmd.h"
#include "Commands/SetShooterSpeedCmd.h"
#include "Commands/KillEverythingCmd.h"
#include "Commands/ToggleIntakeCmd.h"
#include "Commands/SwitchCamerasCmd.h"
#include "Commands/SilkyRotateCmd.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/ReverseShooterCmdGrp.h"
#include "Commands/ShootCmdGrp.h"

OI::OI() {
	// Process operator interface input here.
	driverController.reset(new frc::Joystick(DRIVER_CONTROLLER_PORT));
	operatorController.reset(new frc::Joystick(OPERATOR_CONTROLLER_PORT));

	dIntakeBtn.reset(new frc::JoystickButton(operatorController.get(), OPERATOR_INTAKE_BTN));
	dIntakeBtn->WhenPressed(new ToggleIntakeCmd());
	liftBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_LIFT_BTN));
	liftBtn->WhileHeld(new LiftCmd(1.0));
	lowerBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_LOWER_BTN));
	lowerBtn->WhileHeld(new LiftCmd(-1.0));
	//shooterEnableBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_SHOOT_BTN));
	//shooterEnableBtn->WhileHeld(new ShootCmd());
	increaseSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_INCREASE_SPEED_BTN));
	increaseSpeedBtn->WhenPressed(new IncreaseSpeedCmd());
	decreaseSpeedBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_DECREASE_SPEED_BTN));
	decreaseSpeedBtn->WhenPressed(new DecreaseSpeedCmd());
	openGearFlapsBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_GEAR_FLAP_BTN));
	openGearFlapsBtn->WhileHeld(new OpenGearFlapsCmd());
	shrinkHopperBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_SHRINK_HOPPER_BTN));
	shrinkHopperBtn->WhileHeld(new ExpandHopperCmd());
	keyShotBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_KEY_SHOT_BTN));
	keyShotBtn->WhileHeld(new ShootCmd(KEY_SHOT_SHOOTER_SPEED));
	boilerShotBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_BOILER_SHOT_BTN));
	boilerShotBtn->WhileHeld(new ShootCmdGrp());
	reverseShooterBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_REVERSE_SHOOTER_BTN));
	reverseShooterBtn->WhileHeld(new ReverseShooterCmdGrp());
	operatorKillEverythingBtn.reset(new JoystickButton(operatorController.get(), OPERATOR_KILL_EVERYTHING_BTN));
	operatorKillEverythingBtn->WhenPressed(new KillEverythingCmd());

	driverKillEverythingBtn.reset(new JoystickButton(driverController.get(), DRIVER_KILL_EVERYTHING_BTN));
	driverKillEverythingBtn->WhenPressed(new KillEverythingCmd());
	shiftBtn.reset(new JoystickButton(driverController.get(), DRIVER_SHIFT_BTN));
	shiftBtn->WhenPressed(new ToggleShifterCmd());
	driveForwardsBtn.reset(new JoystickButton(driverController.get(), DRIVER_FORWARDS_BTN));
	driveForwardsBtn->WhileHeld(new DriveForwards());
	driverSwitchCamBtn.reset(new JoystickButton(driverController.get(), DRIVER_SWITCH_CAM_BTN));
	driverSwitchCamBtn->WhenPressed(new SwitchCamerasCmd());
	driverRotateBtn.reset(new JoystickButton(driverController.get(), DRIVER_ROTATE_BTN));
	driverRotateBtn->WhenPressed(new SilkyRotateCmd(15));
	driveTurnBtn.reset(new JoystickButton(driverController.get(), DRIVER_DRIVE_TURN_BTN));
	driveTurnBtn->WhenPressed(new DriveTurnCmd(5));
}

std::shared_ptr<frc::Joystick> OI::getDriverController()
{
   return driverController;
}

std::shared_ptr<frc::Joystick> OI::getOperatorController()
{

	   return operatorController;
}
