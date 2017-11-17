#ifndef DriveInMmCmd_H
#define DriveInMmCmd_H

#include "../CommandBase.h"

class DriveInMmCmd : public CommandBase {
public:
	DriveInMmCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveInMmCmd_H
