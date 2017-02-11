#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <mutex>

#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/LiftSub.h"
//#include "Subsystems/AgitatorSub.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DrivetrainSub> CommandBase::drivetrainSub;
std::unique_ptr<ShooterSub> CommandBase::shooterSub;
std::unique_ptr<LiftSub> CommandBase::liftSub;
std::unique_ptr<IntakeSub> CommandBase::intakeSub;
int CommandBase::x;
int CommandBase::y;
//std::unique_ptr<AgitatorSub> CommandBase::agitatorSub;


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
	oi.reset(new OI());

	std::thread visionThread(VisionThread);
	visionThread.detach();
}

void CommandBase::VisionThread()
{
	cs::AxisCamera axisCamera = frc::CameraServer::GetInstance()->AddAxisCamera(AXIS_ADDRESS);
	grip::GripPipeline gripPipeline;
	frc::CameraServer::GetInstance()->StartAutomaticCapture(axisCamera);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo(axisCamera);
	cv::Mat source;
	while(true) {
		cvSink.GrabFrame(source);
		gripPipeline.Process(source);
		std::cout << gripPipeline.GetFilterContoursOutput()->size() << std::endl;
		for(auto i: *(gripPipeline.GetFilterContoursOutput()))
		{
			cv::Moments M = cv::moments(i);
			x = (M.m10 / M.m00) - AXIS_VISION_RESOLUTION_WIDTH/2;
			std::cout <<"X: "<<  x << std:: endl;
			y = (M.m01 / M.m00) - AXIS_VISION_RESOLUTION_HEIGHT/2;
			std:: cout <<"Y: " <<y <<std:: endl;
		}
	}
}
