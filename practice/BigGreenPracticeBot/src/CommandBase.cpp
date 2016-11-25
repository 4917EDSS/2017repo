#include "CommandBase.h"
#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/IntakeSub.h"
#include "Subsystems/LiftSub.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;
std::unique_ptr<IntakeSub> CommandBase::intakeSub;
std::unique_ptr<LiftSub> CommandBase::liftSub;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrainSub.reset(new DrivetrainSub());
	intakeSub.reset(new IntakeSub());
	liftSub.reset(new LiftSub());

	oi.reset(new OI());
}
