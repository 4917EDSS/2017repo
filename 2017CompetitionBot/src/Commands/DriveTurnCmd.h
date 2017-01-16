#ifndef DriveTurnCmd_H
#define DriveTurnCmd_H

#include "../CommandBase.h"

class DriveTurnCmd : public CommandBase {
public:
	DriveTurnCmd(int angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int targetAngle;
};

#endif  // DriveTurnCmd_H
