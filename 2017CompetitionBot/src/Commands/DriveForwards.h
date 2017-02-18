#ifndef DriveForwards_H
#define DriveForwards_H

#include "../CommandBase.h"
#include <WPILib.h>

class DriveForwards : public CommandBase {
private:
	float accelTime;
public:
	DriveForwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwards_H
