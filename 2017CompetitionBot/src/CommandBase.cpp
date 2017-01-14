#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub = std::make_unique<DrivetrainSub>();
std::unique_ptr<ShooterSub> CommandBase::shooterSub = std::make_unique<ShooterSub>();
std::unique_ptr<IntakeSub> CommandBase::intakeSub = std::make_unique<IntakeSub>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
