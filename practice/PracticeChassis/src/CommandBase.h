#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "frc4917/Log.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DrivetrainSub.h"

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

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	static std::unique_ptr<DrivetrainSub> drivetrainSub;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<frc4917::Log> logger;
};

#endif  // COMMAND_BASE_H
