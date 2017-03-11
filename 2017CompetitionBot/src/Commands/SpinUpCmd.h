#ifndef SpinUpCmd_H
#define SpinUpCmd_H

#include "../CommandBase.h"

class SpinUpCmd : public CommandBase {
public:
	SpinUpCmd(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float speed;
};

#endif  // SpinUpCmd_H
