#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/LiftSub.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;// = std::make_unique<DrivetrainSub>();
std::unique_ptr<ShooterSub> CommandBase::shooterSub;// = std::make_unique<ShooterSub>();
std::unique_ptr<LiftSub> CommandBase::liftSub;

std::unique_ptr<OI> CommandBase::oi; //= std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::Init()
{
	drivetrainSub.reset(new DrivetrainSub());
	shooterSub.reset(new ShooterSub());
	liftSub.reset(new LiftSub());

	oi.reset(new OI());
}
