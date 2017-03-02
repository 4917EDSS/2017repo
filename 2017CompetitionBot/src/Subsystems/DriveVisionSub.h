#ifndef DriveVisionSub_H
#define DriveVisionSub_H

#include <Commands/Subsystem.h>
#include <CameraServer.h>

class DriveVisionSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveVisionSub();
	void switchCam();
	void InitDefaultCommand();
};

#endif  // DriveVisionSub_H
