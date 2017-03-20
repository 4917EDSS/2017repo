#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <mutex>

#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/LiftSub.h"


// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;
std::unique_ptr<ShooterSub> CommandBase::shooterSub;
std::unique_ptr<LiftSub> CommandBase::liftSub;
std::unique_ptr<IntakeSub> CommandBase::intakeSub;
std::unique_ptr<HopperSub> CommandBase::hopperSub;
std::unique_ptr<DriveVisionSub> CommandBase::driveVisionSub;

std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::Init()
{
	drivetrainSub.reset(new DrivetrainSub());
	shooterSub.reset(new ShooterSub());
	liftSub.reset(new LiftSub());
	intakeSub.reset(new IntakeSub());
	driveVisionSub.reset(new DriveVisionSub());
	hopperSub.reset(new HopperSub());
	oi.reset(new OI());

	// Start the vision thread
//	std::thread visionThread(MachineVisionThread);
//	visionThread.detach();
}

