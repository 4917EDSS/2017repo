#include <Commands/MeasureDistanceLidarCmd.h>

MeasureDistanceLidarCmd::MeasureDistanceLidarCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MeasureDistanceLidarCmd::Initialize() {
	// Try out LIDAR
	frc::I2C lidar(frc::I2C::kOnboard, 0x62);
	lidar.Write(0x00, 0x04);
	uint8_t status = 0xA5;

	lidar.Read(0x12, 1, &status);
	std::cout << "LIDAR Reg 12 = " << (int)status << std::endl;

	do {
		lidar.Read(0x01, 1, &status);
	} while(status & 0x01);
	uint8_t data[2];
	lidar.Read(0x8f, 2, data);
	std::cout << "Lidar = " << (((int)data[0] << 8) | data[1]) << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void MeasureDistanceLidarCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MeasureDistanceLidarCmd::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void MeasureDistanceLidarCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MeasureDistanceLidarCmd::Interrupted() {

}
