#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class DrivetrainSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> leftMotor1;
	std::shared_ptr<CANTalon> leftMotor2;
	std::shared_ptr<CANTalon> leftMotor3;
	std::shared_ptr<CANTalon> rightMotor1;
	std::shared_ptr<CANTalon> rightMotor2;
	std::shared_ptr<CANTalon> rightMotor3;
	std::shared_ptr<frc::Encoder> leftMotorEnc;
	std::shared_ptr<frc::Encoder> rightMotorEnc;

public:
	DrivetrainSub();
	void InitDefaultCommand();
	void initHardware();
	void drive(double lSpeed, double rSpeed);
	double getEncoderValue(int encoderId);
};

#endif  // DrivetrainSub_H
