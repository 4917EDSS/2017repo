#ifndef LiftSub_H
#define LiftSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>


class LiftSub : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> liftMotor;
	std::shared_ptr<CANTalon> liftMotor2;


public:
	LiftSub();
	void InitDefaultCommand();
	void SetLiftMotor(float speed);
};

#endif  // LiftSub_H
