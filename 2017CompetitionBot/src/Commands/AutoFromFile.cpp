#include "AutoFromFile.h"
#include "../Components/AutoFile.h"

AutoFromFile::AutoFromFile() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoFromFile::Initialize() {
	af = new AutoFile("/home/lvuser/test.txt");
}

// Called repeatedly when this Command is scheduled to run
void AutoFromFile::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoFromFile::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoFromFile::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoFromFile::Interrupted() {

}
