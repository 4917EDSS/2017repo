#ifndef OI_H
#define OI_H

#include "WPILib.h"

const int DRIVER_CONTROLLER_PORT = 0;

class OI
{
private:
	std::unique_ptr<Joystick> driverController;

public:
	OI();
};

#endif
