#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class DrivetrainSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Note:  These are declared as shared_ptr (not unique_ptr) because we share them with the
	//        LiveWindow for testing purposes.

	// Note2: Instead of explicitly defining two motors per side, we could just configure the
	//        second Talon to slave to the first.  This would allow us to add/remove motors without
	//        changing code.  The down side is that we'd need to configure the Talons to act this
	//        way throught the web interface and this might get forgotten if we ever have to swap
	//        Talons.  For now, do it explicitely.

	std::shared_ptr<CANTalon> leftMotor1;
	std::shared_ptr<CANTalon> leftMotor2;
	std::shared_ptr<CANTalon> rightMotor1;
	std::shared_ptr<CANTalon> rightMotor2;

public:
	DrivetrainSub();
	void InitDefaultCommand();
	void drive( double lSpeed, double rSpeed );
};

#endif  // DrivetrainSub_H
