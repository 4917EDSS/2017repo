#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/DriveForwardCmd.h"
#include "Commands/DriveStopCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	void UpdateSmartDashboard();
	void SendCmdAndSubInfoToSmartDashboard();

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);

		SendCmdAndSubInfoToSmartDashboard();	// Enable for debugging

		printf("Robot initialized (Code built %s)\n", __TIME__);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		UpdateSmartDashboard();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

void Robot::UpdateSmartDashboard()
{
	SmartDashboard::PutBoolean("Limit Switch 1", CommandBase::inputsSub->isSwitchHit(LIMIT_SWITCH1_DIO_PORT));
	SmartDashboard::PutBoolean("Limit Switch 2", CommandBase::inputsSub->isSwitchHit(LIMIT_SWITCH2_DIO_PORT));
}

void Robot::SendCmdAndSubInfoToSmartDashboard()
{
	// See what command is running
	SmartDashboard::PutData(Scheduler::GetInstance());

	// See what command requires a particular subsystem
	if(CommandBase::inputsSub)
		SmartDashboard::PutData((NamedSendable*)(CommandBase::inputsSub.get()));

	// See status of each command and be able to run it manually
	SmartDashboard::PutData("Drive Forward", new DriveForwardCmd());
	SmartDashboard::PutData("Drive Stop", new DriveStopCmd());
}

START_ROBOT_CLASS(Robot)

