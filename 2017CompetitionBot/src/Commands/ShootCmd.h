#ifndef ShootWhileHeldCmd_H
#define ShootWhileHeldCmd_H

#include "../CommandBase.h"

class ShootCmd : public CommandBase {
public:
	ShootCmd(float speed);
	ShootCmd(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool shouldStopAtTime;
	float speed;
	float time;
};

#endif  // ShootWhileHeldCmd_H
