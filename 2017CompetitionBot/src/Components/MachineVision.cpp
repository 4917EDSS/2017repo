/*
 * MachineVision.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: egaudet
 */
#include <WPILib.h>
#include <RobotMap.h>
#include <CommandBase.h>
#include "Components/GripPipeline.h"
#include "MachineVision.h"

struct MachineVisionResults visionResults;

// Machine Vision Results Class
MachineVisionResults::MachineVisionResults()
{
	firstSlotValid = true;
	mvd[0].numCountoursFound = 0;
}

struct MachineVisionData MachineVisionResults::getResults()
{
	// Return valid data slot
	return mvd[firstSlotValid ? 0 : 1];
}

void MachineVisionResults::setResults(struct MachineVisionData newMvd)
{
	// Use currently-invalid slot and then make it the valid slot
	// This is to avoid the situation where date is being read in the middle of when it's being
	// written which is a problem when threads are used.
	mvd[firstSlotValid ? 1 : 0] = newMvd;
	firstSlotValid = !firstSlotValid;
}


void MachineVisionThread()
{
	grip::GripPipeline gripPipeline;
	cv::Mat source;
	int numContoursFound = 0;

	// Setup machine vision
#ifdef HIKCAM
	cs::HttpCamera visionCamera("HikCam", MACHINE_VISION_CAM_ADDRESS );
	frc::CameraServer::GetInstance()->AddCamera(visionCamera);
#else
	cs::AxisCamera visionCamera = frc::CameraServer::GetInstance()->AddAxisCamera(MACHINE_VISION_CAM_ADDRESS);
#endif
	cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo(visionCamera);

	// Need to keep track of the two largest artifacts (constructor initializes to 0s)
	cv::Rect largestRect[2];

	while(true)
	{
		cvSink.GrabFrame(source);
		gripPipeline.Process(source);
		numContoursFound = 0;
		largestRect[0] = cv::Rect ();
		largestRect[1] = cv::Rect ();
		for(auto i: *(gripPipeline.GetFilterContoursOutput()))
		{
			numContoursFound++;

			// Get the rectangle that bounds the contour we've found
			cv::Rect r = cv::boundingRect(i);

			// Only keep the largest two objects (by bounding rectangle area)
			if( (r.width * r.height) > (largestRect[0].width * largestRect[0].height) )
			{
				// This is the biggest one yet
				largestRect[1] = largestRect[0];
				largestRect[0] = r;
			}
			else if( (r.width * r.height) > (largestRect[1].width * largestRect[1].height) )
			{
				// This is the second biggest one so far
				largestRect[1] = r;
			}
			// Else this is smaller than at least two others
		}

		// Report Center X/Y
		struct MachineVisionData mvd;

		mvd.numCountoursFound = numContoursFound;
		mvd.imageWidth = source.cols;
		mvd.imageHeight = source.rows;
		if( numContoursFound > 1 )
		{
			// Find the center between both rectangles
			mvd.x = ((largestRect[0].x + largestRect[0].width/2) + (largestRect[1].x + largestRect[1].width/2)) / 2;
			mvd.y = ((largestRect[0].y + largestRect[0].height/2) + (largestRect[1].y + largestRect[1].height/2)) / 2;
		}
		else if( numContoursFound == 1 )
		{
			// Only one contour found so use its center
			// CAUTION:  In some cases 1 isn't enough so make sure to check numContoursFound
			mvd.x = largestRect[0].x + largestRect[0].width/2;
			mvd.y = largestRect[0].y + largestRect[0].height/2;
		}

		if( numContoursFound > 0 )
		{
			mvd.centerX = mvd.x - source.cols / 2;
			mvd.centerY = mvd.y - source.rows / 2;
		}
		//std::cout << "cX " << mvd.centerX << std::endl;
		visionResults.setResults(mvd);
	}
}




