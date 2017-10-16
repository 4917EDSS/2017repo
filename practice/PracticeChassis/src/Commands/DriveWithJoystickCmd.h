#ifndef DriveWithJoystickCmd_H
#define DriveWithJoystickCmd_H

#include "../CommandBase.h"

class DriveWithJoystickCmd : public CommandBase {
public:
	DriveWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveWithJoystickCmd_H
