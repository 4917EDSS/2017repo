#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "WPILib.h"
#include "AHRS.h"
#include "Components/MotorBalancer.h"
#include "RobotMap.h"

class CommandBase;

class DrivetrainSub : public frc::Subsystem {
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
	std::shared_ptr<frc::Encoder> leftMotorEnc;
	std::shared_ptr<frc::Encoder> rightMotorEnc;
	std::shared_ptr<AHRS> ahrs;
	std::shared_ptr<MotorBalancer> turnBalancer;
	std::shared_ptr<MotorBalancer> motorBalancer;
	std::shared_ptr<frc::PIDController> driveTurnPID;
	std::shared_ptr<frc::PIDController> driveBalanceController;
	std::shared_ptr<frc::DoubleSolenoid> shifter;
	Alliance alliance;

public:
	DrivetrainSub();
	void InitDefaultCommand();
	void drive( double lSpeed, double rSpeed );
	double getLeftEncoder();
	double getRightEncoder();
	double getLeftEncoderSpeed();
	double getRightEncoderSpeed();
	void resetEncoders();
	float getYaw();
	float getPitch();
	float getRoll();
	void resetAHRS();
	void reset();
	void enableTurnPID(double setSpeed);
	void disableTurnPID();
	void PIDTurn();
	bool isTurnFinished();
	void setShifter(frc::DoubleSolenoid::Value shiftState);
	frc::DoubleSolenoid::Value getShifterState();
	void setAlliance(Alliance newAlliance);
	Alliance getAlliance();
	double getLeftEncoderRaw();
	double getRightEncoderRaw();
	void Update(double speed);
	void PIDDrive(float speed);
	void EnableBalancerPID(float setPoint);
	void DisableBalancerPID();
};

#endif  // DrivetrainSub_H
