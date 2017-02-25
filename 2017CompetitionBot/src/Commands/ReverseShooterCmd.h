#ifndef ReverseShooterCmd_H
#define ReverseShooterCmd_H

#include "../CommandBase.h"

class ReverseShooterCmd : public CommandBase {
public:
	ReverseShooterCmd(float newSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float speed;

};

#endif  // ReverseShooterCmd_H
