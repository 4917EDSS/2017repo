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
}


void MachineVisionThread()
{
	grip::GripPipeline gripPipeline;
	cv::Mat source;
	int numContoursFound = 0;

	// Setup machine vision
	cs::HttpCamera hikCamera("HikCam", HIKCAM_ADDRESS );
	frc::CameraServer::GetInstance()->AddCamera(hikCamera);
	cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo(hikCamera);

	// Need to keep track of the two largest artifacts (constructor initializes to 0s)
	cv::Rect largestRect[2];

	while(true)
	{
		cvSink.GrabFrame(source);
		gripPipeline.Process(source);

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
		if( numContoursFound > 1 )
		{
			// Find the center between both rectangles
			mvd.centerX = ((largestRect[0].x + largestRect[0].width/2) + (largestRect[1].x + largestRect[1].width/2)) / 2;
			mvd.centerY = ((largestRect[0].y + largestRect[0].height/2) + (largestRect[1].y + largestRect[1].height/2)) / 2;
		}
		else if( numContoursFound == 1 )
		{
			// Only one contour found so use its center
			// CAUTION:  In some cases 1 isn't enough so make sure to check numContoursFound
			mvd.centerX = largestRect[0].x + largestRect[0].width/2;
			mvd.centerY = largestRect[0].y + largestRect[0].height/2;
		}

		visionResults.setResults(mvd);
	}
}




