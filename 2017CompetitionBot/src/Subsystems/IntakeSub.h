#ifndef IntakeSub_H
#define IntakeSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class IntakeSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> pickupMotor;

public:
	IntakeSub();
	void InitDefaultCommand();
	void setPickupMotor(double speed);
};

#endif  // IntakeSub_H
