#ifndef SwitchCamerasCmd_H
#define SwitchCamerasCmd_H

#include "../CommandBase.h"

class SwitchCamerasCmd : public CommandBase {
public:
	SwitchCamerasCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SwitchCamerasCmd_H
