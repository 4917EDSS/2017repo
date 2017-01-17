#ifndef SetShooterSpeedCmd_H
#define SetShooterSpeedCmd_H

#include "../CommandBase.h"

class SetShooterSpeedCmd : public CommandBase {
private:
	double targetSpeed;
public:
	SetShooterSpeedCmd(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetShooterSpeedCmd_H
