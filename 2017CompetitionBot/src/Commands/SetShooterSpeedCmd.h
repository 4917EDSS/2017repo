#ifndef SetShooterSpeedCmd_H
#define SetShooterSpeedCmd_H

#include "../CommandBase.h"

class SetShooterSpeedCmd : public CommandBase {
public:
	SetShooterSpeedCmd(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float shooterSpeed;
};

#endif  // SetShooterSpeedCmd_H
