#ifndef ShootWhileHeldCmd_H
#define ShootWhileHeldCmd_H

#include "../CommandBase.h"

class ShootCmd : public CommandBase {
public:
	ShootCmd();
	ShootCmd(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool shouldSetSpeed;
	float speed;
};

#endif  // ShootWhileHeldCmd_H
