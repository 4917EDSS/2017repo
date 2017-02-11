#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include <iostream>

DrivetrainSub::DrivetrainSub() : Subsystem("DrivetrainSub") {
	leftMotor1.reset(new CANTalon(LEFT1_DRIVE_MOTOR_CANID));
	leftMotor2.reset(new CANTalon(LEFT2_DRIVE_MOTOR_CANID));
	rightMotor1.reset(new CANTalon(RIGHT1_DRIVE_MOTOR_CANID));
	rightMotor2.reset(new CANTalon(RIGHT2_DRIVE_MOTOR_CANID));
	leftMotorEnc.reset(new frc::Encoder(LEFT_MOTOR_ENC1_DIO, LEFT_MOTOR_ENC2_DIO));
	rightMotorEnc.reset(new frc::Encoder(RIGHT_MOTOR_ENC1_DIO, RIGHT_MOTOR_ENC2_DIO));
	leftMotorEnc->SetDistancePerPulse(DRIVETRAIN_DIS_PER_PULSE);
	rightMotorEnc->SetDistancePerPulse(DRIVETRAIN_DIS_PER_PULSE);
	shifter.reset(new frc::DoubleSolenoid(SHIFTER_PCM_ID1, SHIFTER_PCM_ID2));
	turnBalancer.reset(new MotorBalancer());
	ahrs.reset(new AHRS(AHRSInterface));
	Preferences *prefs = Preferences::GetInstance();
	driveTurnPID.reset(new frc::PIDController(prefs->GetFloat("DriveTurnP", DRIVE_TURN_P),
			   	   	   	   	   	   	   	   	  prefs->GetFloat("DriveTurnI", DRIVE_TURN_I),
											  prefs->GetFloat("DriveTurnD", DRIVE_TURN_D), ahrs.get(), turnBalancer.get()));

	// Make these properly available in Test mode
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	lw->AddActuator("Drivetrain", "Left Motor 1", leftMotor1);
	lw->AddActuator("Drivetrain", "Left Motor 2", leftMotor2);
	lw->AddActuator("Drivetrain", "Right Motor 1", rightMotor1);
	lw->AddActuator("Drivetrain", "Right Motor 2", rightMotor2);
}

void DrivetrainSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::drive(double lSpeed, double rSpeed)
{
	leftMotor1->Set(lSpeed);
	leftMotor2->Set(lSpeed);
	rightMotor1->Set(-rSpeed);
	rightMotor2->Set(-rSpeed);
}
void DrivetrainSub::setAlliance(Alliance newAlliance)
{
	alliance = newAlliance;
}

Alliance DrivetrainSub::getAlliance()
{
	return alliance;
}
double DrivetrainSub::getLeftEncoderSpeed()
{
	return leftMotorEnc->GetRate();
}
double DrivetrainSub::getRightEncoderSpeed()
{
	return rightMotorEnc->GetRate();
}
double DrivetrainSub::getLeftEncoder()
{
	return leftMotorEnc->GetDistance();
}
double DrivetrainSub::getRightEncoder()
{
	return rightMotorEnc->GetDistance();
}
void DrivetrainSub::reset() {
	resetAHRS();
	resetEncoders();
}
void DrivetrainSub::resetAHRS()
{
	ahrs->ZeroYaw();
}
void DrivetrainSub::resetEncoders(){
	leftMotorEnc->Reset();
	rightMotorEnc->Reset();
}
float DrivetrainSub::getYaw(){
	return ahrs->GetYaw();
}
float DrivetrainSub::getPitch(){
	return ahrs->GetPitch();
}
float DrivetrainSub::getRoll(){
	return ahrs->GetRoll();
}
void DrivetrainSub::enableTurnPID(double setPoint)
{
	Preferences *prefs = Preferences::GetInstance();
	driveTurnPID->SetPID(prefs->GetFloat("DriveTurnP", DRIVE_TURN_P), prefs->GetFloat("DriveTurnI", DRIVE_TURN_I), prefs->GetFloat("DriveTurnD", DRIVE_TURN_D));
	driveTurnPID->SetAbsoluteTolerance(prefs->GetFloat("DriveTurnTolerance", DRIVE_TURN_TOLERANCE));
	driveTurnPID->SetSetpoint(setPoint);
	//driveTurnPID->SetOutputRange(prefs->GetFloat("DriveTurnMinimum", DRIVE_TURN_TOLERANCE), prefs->GetFloat("DriveTurnMaximum", DRIVE_TURN_TOLERANCE));
	driveTurnPID->Enable();
}
void DrivetrainSub::disableTurnPID(){
	driveTurnPID->Disable();
}
void DrivetrainSub::PIDTurn()
{
	std::cout << "SP=" << driveTurnPID->GetSetpoint() << std::endl;
	leftMotor1->Set(turnBalancer->GetDifference());
	leftMotor2->Set(turnBalancer->GetDifference());
	rightMotor1->Set(turnBalancer->GetDifference());
	rightMotor2->Set(turnBalancer->GetDifference());
}
bool DrivetrainSub::isTurnFinished(){
	return driveTurnPID->OnTarget();
}
void DrivetrainSub::setShifter(frc::DoubleSolenoid::Value shiftState){
	shifter->Set(shiftState);
}
frc::DoubleSolenoid::Value DrivetrainSub::getShifterState(){
	return shifter->Get();
}

double DrivetrainSub::getLeftEncoderRaw()
{
	return leftMotorEnc->GetRaw();
}
double DrivetrainSub::getRightEncoderRaw()
{
	return rightMotorEnc->GetRaw();
}
