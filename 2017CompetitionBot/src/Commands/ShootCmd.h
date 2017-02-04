#ifndef ShootWhileHeldCmd_H
#define ShootWhileHeldCmd_H

#include "../CommandBase.h"

class ShootCmd : public CommandBase {
public:
	ShootCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootWhileHeldCmd_H
