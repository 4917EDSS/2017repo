#include "InputsSub.h"
#include "../RobotMap.h"

InputsSub::InputsSub() :
		Subsystem("InputSub")
{
	limitSwitch1In.reset(new DigitalInput(LIMIT_SWITCH1_DIO_PORT));
	limitSwitch2In.reset(new DigitalInput(LIMIT_SWITCH2_DIO_PORT));
}

void InputsSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool InputsSub::isSwitchHit(int switchPort)
{
	bool state = false;

	switch(switchPort)
	{
	case LIMIT_SWITCH1_DIO_PORT:
		state = !limitSwitch1In->Get();
		break;
	case LIMIT_SWITCH2_DIO_PORT:
		state = !limitSwitch2In->Get();
		break;
	default:
		break;
	}

	return state;
}
