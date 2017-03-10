//============================================================================
// Name        : GripOffline.cpp
// Author      : Eric Gaudet
// Version     :
// Copyright   : (C)2017
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "MachineVision.h"
#include "GripPipeline.h"

using namespace std;

int main() {
	grip::GripPipeline gripPipeline;
	cv::Mat source;
	int numContoursFound = 0;

	cout << "Starting..." << endl;

	// Setup machine vision
#ifdef ONLINE
	cs::HttpCamera hikCamera("HikCam", HIKCAM_ADDRESS );
	frc::CameraServer::GetInstance()->AddCamera(hikCamera);
	cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo(hikCamera);

	cvSink.GrabFrame(source);
#else
	source = cv::imread("/home/frc4917/repos/2017repo/GRIP/SampleImages/geartarget/1-1000_gain10_3.png");
#endif

	// Need to keep track of the two largest artifacts (constructor initializes to 0s)
	cv::Rect largestRect[2];

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
    	std::cout << "Rect X=" << r.x << " Y=" << r.y << " W=" << r.width << " H=" << r.height << endl;
    	cv::rectangle(source, r, cv::Scalar(0xFF,0xFF,0xFF), 1);
#endif
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

	cv::Rect r(mvd.centerX-1,mvd.centerY-1,3,3);
	cv::rectangle(source, r, cv::Scalar(0x00,0x00,0xFF),1);
	std::cout << "CenterX=" << mvd.centerX << " CenterY=" << mvd.centerY << " NumCont=" << mvd.numCountoursFound << endl;

    cv::namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Display Image", source );
    cv::waitKey(0);



	return 0;
}
