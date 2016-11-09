#ifndef LiftSub_H
#define LiftSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> liftMotor;
	//std::unique_ptr<Encoder> liftMotorEncoder;
	std::unique_ptr<DoubleSolenoid> lockOpenCloseActuators;
	std::unique_ptr<DoubleSolenoid> lockInOutActuators;
	std::unique_ptr<DigitalInput> topLimitSwitch;
	//std::unique_ptr<DigitalInput> bottomLimitSwitch;
public:
	LiftSub();
	void InitDefaultCommand();
};

#endif
