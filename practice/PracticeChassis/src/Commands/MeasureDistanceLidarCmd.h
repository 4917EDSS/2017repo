#ifndef MesureDistanceLidarCmd_H
#define MesureDistanceLidarCmd_H

#include "../CommandBase.h"

class MeasureDistanceLidarCmd : public CommandBase {
public:
	MeasureDistanceLidarCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MesureDistanceLidarCmd_H
