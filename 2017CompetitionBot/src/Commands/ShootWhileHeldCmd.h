#ifndef ShootWhileHeldCmd_H
#define ShootWhileHeldCmd_H

#include "../CommandBase.h"

class ShootWhileHeldCmd : public CommandBase {
public:
	ShootWhileHeldCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootWhileHeldCmd_H
