#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/DriveWithJoystickCmd.h"									// TODO: Change this to a valid AUTO command!
#include "CommandBase.h"
#include "Commands/AutoDefaultGrp.h"
#include "Commands/AutoLoadStraightGrp.h"
#include "Commands/DriveStraightCmd.h"


class Robot: public frc::IterativeRobot {
public:

	void RobotInit() override {
		CommandBase::Init();
		SetSmartDashboardAutoOptions();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		/*if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		}
		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
		*/
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
		SetSmartDashboardDriverContent();
	}
	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		UpdateSmartDashboard();
	}
	void TestPeriodic() override {
		std::printf("TestPeriodic");
		frc::LiveWindow::GetInstance()->Run();
	}
private:
	std::unique_ptr<frc::Command> autonomousCommand;
	std::unique_ptr<frc::Command> autoLocation;
	std::unique_ptr<frc::SendableChooser<CommandBase::Alliance> > autoAllianceOptions;
	std::unique_ptr<frc::SendableChooser<std::shared_ptr<frc::Command>> > autoLocationOptions;
	void UpdateSmartDashboard()
	{
		SmartDashboard::PutNumber("Left Drive Motor Enc", CommandBase::drivetrainSub->getLeftEncoder());
		SmartDashboard::PutNumber("Right Drive Motor Enc", CommandBase::drivetrainSub->getRightEncoder());
	}
	void SetSmartDashboardAutoOptions()
	{
		autoAllianceOptions.reset(new frc::SendableChooser<CommandBase::Alliance>());
		autoAllianceOptions->AddObject("Red", CommandBase::Alliance::RED);
		autoAllianceOptions->AddObject("Blue", CommandBase::Alliance::BLUE);

		autoLocationOptions.reset(new frc::SendableChooser<std::shared_ptr<frc::Command>>());
		autoLocationOptions->AddDefault("Do Nothing", std::shared_ptr<frc::Command>(new AutoDefaultGrp()));
		autoLocationOptions->AddObject("Load Straight", std::shared_ptr<frc::Command>(new AutoLoadStraightGrp()));
		/*autoLocationOptions->AddObject("Load Left", new AutoPosition2ShootGrp());
		autoLocationOptions->AddObject("Load Right", new AutoPosition2ShootLeftGrp());
		autoLocationOptions->AddObject("Load Left Shoot", new AutoPosition3ShootGrp());
		autoLocationOptions->AddObject("Load Right Shoot", new AutoPosition3ShootRightGrp());
		autoLocationOptions->AddObject("Load Straight Shoot", new AutoPosition4ShootGrp());
		autoLocationOptions->AddObject("Load Straight Around", new AutoPosition5ShootGrp());
*/
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Alliance", autoAllianceOptions.get());
		SmartDashboard::PutData("Auto Modes ", autoLocationOptions.get());
	}
	void SetSmartDashboardDriverContent()
	{
		SmartDashboard::PutData("Drive mostly straight", new DriveStraightCmd(LOAD_STRAIGHT_DIST));
		//SmartDashboard::PutData("Hopefully Turn", new DriveTurnCmd(LOAD_STRAIGHT_DIST));
	}
};

START_ROBOT_CLASS(Robot)
