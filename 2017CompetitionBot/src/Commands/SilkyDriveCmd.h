#ifndef SilkyDriveCmd_H
#define SilkyDriveCmd_H

#include "../CommandBase.h"
#include "Components/SilkyMotionManager.h"
#include <vector>

class SilkyDriveCmd : public CommandBase {
private:
	SilkyMotionManager smm;
public:
	SilkyDriveCmd(std::vector<double> leftPositions, std::vector<double> rightPositions);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
