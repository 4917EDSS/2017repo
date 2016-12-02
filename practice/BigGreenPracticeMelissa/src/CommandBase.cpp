#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<ExampleSubsystem> CommandBase::examplesubsystem;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;

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
	examplesubsystem.reset(new ExampleSubsystem());
	drivetrainSub.reset(new DrivetrainSub());
	oi.reset(new OI());
}
