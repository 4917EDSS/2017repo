#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <WPILib.h>
#include <vector>

#include "Commands/DriveWithJoystickCmd.h"									// TODO: Change this to a valid AUTO command!
#include "CommandBase.h"
#include "Commands/AutoDefaultGrp.h"
#include "Commands/AutoCenterGearShootGrp.h"
#include "Commands/AutoBoilerGearShootGrp.h"
#include "Commands/AutoLoaderGearGrp.h"
#include "Commands/AutoHopperShootGrp.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/SilkyDriveCmd.h"
#include "Commands/ResetDriveEncodersCmd.h"
#include "Commands/AHRSDriveStraightCmd.h"
#include "Commands/AutoBoilerGearShootGrp.h"
#include "Commands/AutoCenterGearShootGrp.h"
#include "Commands/AutoHopperShootGrp.h"
#include "Commands/AutoShootGrp.h"
#include "Commands/AutoCenterGearGrp.h"

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
		}*/
		autonomousCommand = autoLocationOptions->GetSelected();

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
		CommandBase::drivetrainSub->setShifter(frc::DoubleSolenoid::Value::kForward);

	}

	void AutonomousPeriodic() override {
		UpdateSmartDashboard();
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
		//std::cout << "X: " << CommandBase::getCentreX() << std::endl;
	}
	void TestPeriodic() override {
		std::printf("TestPeriodic");
		frc::LiveWindow::GetInstance()->Run();
	}
private:
	std::shared_ptr<frc::Command> autonomousCommand;
	std::unique_ptr<frc::Command> autoLocation;
	std::unique_ptr<frc::SendableChooser<std::shared_ptr<frc::Command> > > autoLocationOptions;
	void UpdateSmartDashboard()
	{
		SmartDashboard::PutNumber("Left Drive Motor Enc", CommandBase::drivetrainSub->getLeftEncoder());
		SmartDashboard::PutNumber("Right Drive Motor Enc", CommandBase::drivetrainSub->getRightEncoder());
		SmartDashboard::PutNumber("Yaw", CommandBase::drivetrainSub->getYaw());
		SmartDashboard::PutNumber("Pitch", CommandBase::drivetrainSub->getPitch());
		SmartDashboard::PutNumber("Roll", CommandBase::drivetrainSub->getRoll());
		SmartDashboard::PutNumber("Real Shooter Speed", CommandBase::shooterSub->getSpeed());
		SmartDashboard::PutNumber("Target Shooter Speed", CommandBase::shooterSub->getTargetSpeed());
		SmartDashboard::PutNumber("Raw Left Encoder", CommandBase::drivetrainSub->getLeftEncoderRaw());
		SmartDashboard::PutNumber("Raw Right Encoder", CommandBase::drivetrainSub->getRightEncoderRaw());
		SmartDashboard::PutNumber("Right Encoder Speed", CommandBase::drivetrainSub->getRightEncoderSpeed());
		SmartDashboard::PutNumber("Left Encoder Speed", CommandBase::drivetrainSub->getLeftEncoderSpeed());
		SmartDashboard::PutNumber("Left Drive Amps1", CommandBase::drivetrainSub-> getLeftAmps1());
		SmartDashboard::PutNumber("Left Drive Amps2", CommandBase::drivetrainSub-> getLeftAmps2());
		SmartDashboard::PutNumber("Right Drive Amps1", CommandBase::drivetrainSub->getRightAmps1());
		SmartDashboard::PutNumber("Right Drive Amps2", CommandBase::drivetrainSub->getRightAmps2());
		SmartDashboard::PutBoolean("Intake While Driving", CommandBase::intakeSub->getIntakeWhenMoving());
	}
	void SetSmartDashboardAutoOptions()
	{

		autoLocationOptions.reset(new frc::SendableChooser<std::shared_ptr<frc::Command> >());
		autoLocationOptions->AddDefault("Do Nothing", std::shared_ptr<frc::Command>(new AutoDefaultGrp()));
		autoLocationOptions->AddObject("Hopper Shoot", std::shared_ptr<frc::Command>(new AutoHopperShootGrp()));
		autoLocationOptions->AddObject("BoilerGear Shoot", std::shared_ptr<frc::Command>(new AutoBoilerGearShootGrp()));
		autoLocationOptions->AddObject("CenterGear Shoot", std::shared_ptr<frc::Command>(new AutoCenterGearShootGrp()));
		autoLocationOptions->AddObject("LoaderGear", std::shared_ptr<frc::Command>(new AutoLoaderGearGrp()));
		autoLocationOptions->AddObject("CenterGear", std::shared_ptr<frc::Command>(new AutoCenterGearGrp()));
		autoLocationOptions->AddObject("Immediately Shoot, No Gear", std::shared_ptr<frc::Command>(new AutoShootGrp()));

		SmartDashboard::PutData("Auto Modes", autoLocationOptions.get());
	}
	void SetSmartDashboardDriverContent()
	{
		SmartDashboard::PutData("Drive mostly straight", new DriveStraightCmd(LOAD_STRAIGHT_DIST));
		SmartDashboard::PutData("reset encoders", new ResetDriveEncodersCmd());
		SmartDashboard::PutData("Drive straight with navx", new AHRSDriveStraightCmd(1000, 0.7));
		//SmartDashboard::PutData("Hopefully Turn", new DriveTurnCmd(LOAD_STRAIGHT_DIST));
	}

};

START_ROBOT_CLASS(Robot)
