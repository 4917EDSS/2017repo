#ifndef OI_H
#define OI_H
const int DRIVER_CONTROLLER_PORT =0;

#include "WPILib.h"

class OI
{
private:
	std::unique_ptr<Joystick>driverController;

public:
	OI();
};

#endif
