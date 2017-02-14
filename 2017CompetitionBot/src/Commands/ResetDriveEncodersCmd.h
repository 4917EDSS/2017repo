#ifndef ResetDriveEncodersCmd_H
#define ResetDriveEncodersCmd_H

#include "../CommandBase.h"
#include <WPILib.h>

class ResetDriveEncodersCmd : public CommandBase {
public:
	ResetDriveEncodersCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetDriveEncodersCmd_H
