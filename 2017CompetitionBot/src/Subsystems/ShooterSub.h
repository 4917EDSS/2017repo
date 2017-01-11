#ifndef ShooterSub_H
#define ShooterSub_H

#include <Commands/Subsystem.h>

class ShooterSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	ShooterSub();
	void InitDefaultCommand();
};

#endif  // ShooterSub_H
