#include "DriveVisionSub.h"
#include "../RobotMap.h"

// There are a couple of ways that this may work.  Un-comment ONE label to turn on that method and try it.
#define MULTI_CAMERAS
//#define SWITCHING_CAMERAS
//#define SHARED_NAME_SWITCHING_CAMERAS
//#define SECOND_CAM

DriveVisionSub::DriveVisionSub() : Subsystem("DriveVisionSub") {
#ifdef MULTI_CAMERAS
	// This method has both USB cameras going the whole time (no switching on the Rio)
	frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam1", "/dev/video0");
	frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam2", "/dev/video1");
#endif

#ifdef SWITCHING_CAMERAS
	frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam1", "/dev/video0");
#endif

#ifdef SHARED_NAME_SWITCHING_CAMERAS
	frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam", "/dev/video0");
#endif

#ifdef SECOND_CAM
	frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam2", "/dev/video1");
#endif
}

void DriveVisionSub::switchCam() {
#ifdef MULTI_CAMERAS
#endif

#ifdef SWITCHING_CAMERAS
	static int curCam = 1;

	if( curCam == 1 )
	{
		frc::CameraServer::GetInstance()->RemoveServer("usbCam1");
		frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam2", "/dev/video1");
		curCam = 2;
	}
	else
	{
		frc::CameraServer::GetInstance()->RemoveServer("usbCam2");
		frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam1", "/dev/video0");
		curCam = 1;
	}
#endif

#ifdef SHARED_NAME_SWITCHING_CAMERAS
	static int curCam = 1;

	frc::CameraServer::GetInstance()->RemoveServer("usbCam");
	if( curCam == 1 )
	{
		frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam", "/dev/video1");
		curCam = 2;
	}
	else
	{
		frc::CameraServer::GetInstance()->StartAutomaticCapture("usbCam", "/dev/video0");
		curCam = 1;
	}
#endif
}


void DriveVisionSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
