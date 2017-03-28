#ifndef SilkyDriveCmd_H
#define SilkyDriveCmd_H

#include "../CommandBase.h"
#include "Components/SilkyMotionManager.h"
#include <vector>

class SilkyDriveCmd : public CommandBase {
private:
	SilkyMotionManager smmBlue;
	SilkyMotionManager smmRed;
	SilkyMotionManager* smm;
public:
	SilkyDriveCmd(std::vector<double> leftPositions, std::vector<double> rightPositions);
	SilkyDriveCmd(std::vector<double> leftPostionsBlue, std::vector<double> rightPostitionsBlue, std::vector<double> leftPositionsRed, std::vector<double> rightPositionsRed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
