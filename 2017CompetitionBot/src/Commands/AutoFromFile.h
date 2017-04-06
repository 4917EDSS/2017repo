#ifndef AutoFromFile_H
#define AutoFromFile_H

#include "../CommandBase.h"
#include "../Components/AutoFile.h"

class AutoFromFile : public CommandBase {
private:
	AutoFile* af;
public:
	AutoFromFile();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoFromFile_H
