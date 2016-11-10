#ifndef IntakeSub_H
#define IntakeSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> leftMotor;
	std::unique_ptr<CANTalon> rightMotor;
	std::unique_ptr<Solenoid> beltArmsOpenCloseActuator;
	std::unique_ptr<DigitalInput> rearLimitSwitch;
public:
	IntakeSub();
	void InitDefaultCommand();
	void SetIntakeSpeed(float speed);
	void SetArmsOpenClose(bool open);
	void ToggleArmsOpenClose();
	bool IsRearLimitSwitchHit();
};

#endif
