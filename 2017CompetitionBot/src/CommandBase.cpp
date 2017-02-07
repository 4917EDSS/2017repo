#include "CommandBase.h"

#include <Commands/Scheduler.h>

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
//std::unique_ptr<AgitatorSub> CommandBase::agitatorSub;


std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<cs::AxisCamera> axisCamera;
std::unique_ptr<grip::GripPipeline> gripPipeline;
std::unique_ptr<cs::CvSink> cvSink;

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
	//axisCamera.reset(frc::CameraServer::GetInstance()->AddAxisCamera(AXIS_ADDRESS));
	//frc::CameraServer::GetInstance()->StartAutomaticCapture(*axisCamera);
	//cvSink.reset(new cs::CvSink(CameraServer::GetInstance()->GetVideo()));
}
/*
void CommandBase::cameraTest() {
		cv::Mat source;
		cvSink->GrabFrame(source);
		gripPipeline->Process(source);
		std::cout << gripPipeline->GetFilterContoursOutput()->size() << std::endl;
		for(auto i: *(gripPipeline->GetFilterContoursOutput()))
		{
			cv::Moments M = cv::moments(i);
			double x = (M.m10 / M.m00);
			double y = (M.m01 / M.m00);
			std::cout << "(" << x << ", " << y << ")" << std::endl;
		}
		std::cout << std::endl;
	}
*/
