#include "HopperPulseCmd.h"

HopperPulseCmd::HopperPulseCmd(float time) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	totalTime = time;
	openHopperNext = true;
}

// Called just before this Command runs the first time
void HopperPulseCmd::Initialize() {
	openHopperNext = true;
	nextEventTime = HOPPER_CLOSE_TIME;
}

// Called repeatedly when this Command is scheduled to run
void HopperPulseCmd::Execute() {
	if (TimeSinceInitialized() > nextEventTime){
		if(openHopperNext){
			hopperSub->expandHopper();
			openHopperNext = false;
			nextEventTime = TimeSinceInitialized() + HOPPER_OPEN_TIME;
		}
		else {
			hopperSub->shrinkHopper();
			openHopperNext = true;
			nextEventTime = TimeSinceInitialized() + HOPPER_CLOSE_TIME;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool HopperPulseCmd::IsFinished() {
	if(TimeSinceInitialized() > totalTime){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void HopperPulseCmd::End() {
	hopperSub->shrinkHopper();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HopperPulseCmd::Interrupted() {
	End();
}
