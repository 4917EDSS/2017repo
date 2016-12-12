#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include <algorithm>

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	motor1.reset(new CANTalon(MOTOR1_CANID));
	motor2.reset(new CANTalon(MOTOR2_CANID));
	motorEnc1.reset(new Encoder(MOTOR_ENC1_DIO));
	motorEnc2.reset(new Encoder(MOTOR_ENC2_DIO));
	shifter.reset(new DoubleSolenoid(SHIFTER_DIO));
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSub::drive(float oneSpeed, float twoSpeed)
{
	motor1->Set(oneSpeed);
	motor2->Set(twoSpeed);
}

void DrivetrainSub::shift(ShiftState gear){
	if(gear == ShiftState::HIGH){
		shifter->Set(DoubleSolenoid::Value::kForward);
	}
	else if(gear == ShiftState::LOW){
		shifter->Set(DoubleSolenoid::Value::kReverse);
	}
}

DrivetrainSub::ShiftState DrivetrainSub::getGear(){
	if(shifter->Get() == DoubleSolenoid::Value::kForward){
			return ShiftState::HIGH;
		}
	else if(shifter->Get() == DoubleSolenoid::Value::kReverse){
			return ShiftState::LOW;
		}
}

double DrivetrainSub::getDriveRate(){
	return std::max(motorEnc1->GetRate(), motorEnc2->GetRate());
}
