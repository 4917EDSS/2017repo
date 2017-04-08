#ifndef AutoFromFileCmdGrp_H
#define AutoFromFileCmdGrp_H

#include <Commands/CommandGroup.h>
#include <WPILib.h>

class AutoFromFileCmdGrp : public CommandGroup {
private:
	CommandGroup* delegate;
public:
	AutoFromFileCmdGrp();
	CommandGroup* prepareDelegate();
};

#endif  // AutoFromFileCmdGrp_H
