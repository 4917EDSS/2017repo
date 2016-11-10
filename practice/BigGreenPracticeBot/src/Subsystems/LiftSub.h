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
	std::unique_ptr<Solenoid> lockOpenCloseActuator;
	std::unique_ptr<Solenoid> lockInOutActuator;
	std::unique_ptr<DigitalInput> topLimitSwitch;
	//std::unique_ptr<DigitalInput> bottomLimitSwitch;
public:
	LiftSub();
	void InitDefaultCommand();
	void SetLiftSpeed(float speed);
	void SetLocksOpenClosed(bool open);
	void ToggleLocksOpenClosed();
	void SetLockInOut(bool in);
	void ToggleLocksInOut();
	bool IsTopLimitSwitchHit();
};

#endif
