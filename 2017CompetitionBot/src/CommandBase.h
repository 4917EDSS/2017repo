#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/HopperSub.h"
#include "Subsystems/IntakeSub.h"
#include "Subsystems/LiftSub.h"
#include "Subsystems/DriveVisionSub.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "Components/GripPipeline.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void Init();
	static void VisionThread();
	static int getCentreX();
	static int x;
	static int y;
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DrivetrainSub> drivetrainSub;
	static std::unique_ptr<ShooterSub> shooterSub;
	static std::unique_ptr<IntakeSub> intakeSub;
	static std::unique_ptr<LiftSub> liftSub;
	static std::unique_ptr<DriveVisionSub> driveVisionSub;
	static std::unique_ptr<HopperSub> hopperSub;
	static std::unique_ptr<OI> oi;
//	static std::unique_ptr<cs::AxisCamera> axisCamera;
//	static std::unique_ptr<grip::GripPipeline> gripPipeline;
//	static std::unique_ptr<cs::CvSink> cvSink;
//	static void cameraTest();


};

#endif  // COMMAND_BASE_H
