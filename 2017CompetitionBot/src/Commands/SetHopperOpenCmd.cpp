#include "SetHopperOpenCmd.h"

SetHopperOpenCmd::SetHopperOpenCmd(bool open) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(hopperSub.get());
	this->open = open;
}

// Called just before this Command runs the first time
void SetHopperOpenCmd::Initialize() {
	if(open) {
		hopperSub->expandHopper();
	} else {
		hopperSub->shrinkHopper();
	}
}

// Called repeatedly when this Command is scheduled to run
void SetHopperOpenCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetHopperOpenCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetHopperOpenCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetHopperOpenCmd::Interrupted() {

}
