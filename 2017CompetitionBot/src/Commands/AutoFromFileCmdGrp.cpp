#include "AutoFromFileCmdGrp.h"
#include "Commands/CommandGroup.h"
#include "Components/AutoFile.h"
#include "RobotMap.h"

AutoFromFileCmdGrp::AutoFromFileCmdGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	delegate = nullptr;
}

CommandGroup* AutoFromFileCmdGrp::prepareDelegate() {
	if(delegate) {
		//delete(delegate);
		delegate = nullptr;
	}

	delegate = new CommandGroup();
	AutoFile af(AUTO_FILENAME);
	std::vector<AutoFile::Operation>& commands = af.readFile();
	for(unsigned int i = 0; i < commands.size(); i++) {
		if(commands[i].second) {
			delegate->AddParallel(commands[i].first);
		} else {
			delegate->AddSequential(commands[i].first);
		}
	}
	return delegate;
}
