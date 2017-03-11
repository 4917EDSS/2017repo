/*
 * MachineVision.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: egaudet
 */
#include <iostream>
#include "GripPipeline.h"
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
	source = cv::imread("/home/frc4917/repos/2017repo/GRIP/SampleImages/boilertarget/1-1000_gain10_3.png");

	// Need to keep track of the two largest artifacts (constructor initializes to 0s)
	cv::Rect largestRect[2];

	{
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
#ifndef ONLINE
    	std::cout << "Rect X=" << r.x << " Y=" << r.y << " W=" << r.width << " H=" << r.height << std::endl;
    	cv::rectangle(source, r, cv::Scalar(0xFF,0xFF,0xFF), 1);
#endif
		}

		// Report Center X/Y
		struct MachineVisionData mvd;

		mvd.numCountoursFound = numContoursFound;
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

		visionResults.setResults(mvd);


#ifndef ONLINE
    	cv::Rect r(mvd.x-1,mvd.y-1,3,3);
    	cv::rectangle(source, r, cv::Scalar(0x00,0x00,0xFF),1);
    	std::cout << "Actual X,Y=(" << mvd.x << "," << mvd.y << ") CenterX,Y=(" << mvd.centerX << "," << mvd.centerY << ") NumCont=" << mvd.numCountoursFound <<
    			" ImgSize=(" << source.cols << "," << source.rows << ")" << std::endl;

        cv::namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
        cv::imshow( "Display Image", source );
        cv::waitKey(0);
#endif
	}
}




