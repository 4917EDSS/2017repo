#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <mutex>

#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/LiftSub.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;
std::unique_ptr<ShooterSub> CommandBase::shooterSub;
std::unique_ptr<LiftSub> CommandBase::liftSub;
std::unique_ptr<IntakeSub> CommandBase::intakeSub;
std::unique_ptr<HopperSub> CommandBase::hopperSub;
std::unique_ptr<DriveVisionSub> CommandBase::driveVisionSub;
int CommandBase::x;
int CommandBase::y;


std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::Init()
{
	drivetrainSub.reset(new DrivetrainSub());
	shooterSub.reset(new ShooterSub());
	liftSub.reset(new LiftSub());
	intakeSub.reset(new IntakeSub());
	driveVisionSub.reset(new DriveVisionSub());
	hopperSub.reset(new HopperSub());
	oi.reset(new OI());

	std::thread visionThread(VisionThread);
	visionThread.detach();
}

void CommandBase::VisionThread()
{
#ifdef AXIS_CAM
	cs::AxisCamera axisCamera = frc::CameraServer::GetInstance()->AddAxisCamera("AXIS M1013", AXIS_ADDRESS);
	frc::CameraServer::GetInstance()->AddCamera(axisCamera);
	frc::CameraServer::GetInstance()->StartAutomaticCapture(axisCamera);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo(axisCamera);
#else
	cs::HttpCamera hikCamera("HikCam", "http://admin:4917sirlancerbot@10.49.17.11/Streaming/channels/102/httppreview" );//, HttpCamera::HttpCameraKind::kMJPGStreamer);

	frc::CameraServer::GetInstance()->AddCamera(hikCamera);
	frc::CameraServer::GetInstance()->StartAutomaticCapture();
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo(hikCamera);
#endif

	grip::GripPipeline gripPipeline;
	cv::Mat source;
	while(true) {
		std::cerr << "Before GrabFrame" << std::endl;
		cvSink.GrabFrame(source);
		std::cerr << "After GrabFrame" << std::endl;
		gripPipeline.Process(source);
		std::cerr << "After Process" << std::endl;
		//std::cout << gripPipeline.GetFindContoursOutput()->size() << std::endl;
		for(auto i: *(gripPipeline.GetFindContoursOutput()))
		{
			cv::Moments M = cv::moments(i);
			x = (M.m10 / M.m00) - AXIS_VISION_RESOLUTION_WIDTH/2;
		//	std::cout <<"X: "<<  x << std:: endl;
			y = (M.m01 / M.m00) - AXIS_VISION_RESOLUTION_HEIGHT/2;
		//	std:: cout <<"Y: " <<y <<std:: endl;
		}
	}
}
