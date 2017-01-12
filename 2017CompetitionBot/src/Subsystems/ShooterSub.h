#ifndef ShooterSub_H
#define ShooterSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class ShooterSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Note:  These are declared as shared_ptr (not unique_ptr) because we share them with the
	//        LiveWindow for testing purposes.

	std::shared_ptr<CANTalon> topMotor;
	std::shared_ptr<CANTalon> bottomMotor;

public:
	ShooterSub();
	void InitDefaultCommand();
	void setShooterSpeed(double tSpeed, double bSpeed);
};

#endif  // ShooterSub_H
