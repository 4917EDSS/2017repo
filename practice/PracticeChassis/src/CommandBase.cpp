#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/ExampleSubsystem.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem = std::make_unique<ExampleSubsystem>();
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub = std::make_unique<DrivetrainSub>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<frc4917::Log> CommandBase::logger = std::make_unique<frc4917::Log>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
