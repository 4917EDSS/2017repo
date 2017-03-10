//============================================================================
// Name        : GripOffline.cpp
// Author      : Eric Gaudet
// Version     :
// Copyright   : (C)2017
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "GripPipeline.h"

using namespace std;

int main() {
	grip::GripPipeline gripPipeline;

	cout << "Starting..." << endl;

	cv::Mat image;
    image = cv::imread("/home/frc4917/repos/2017repo/GRIP/SampleImages/geartarget/1-1000_gain10_3.png");

    gripPipeline.Process(image);

    for(auto i: *(gripPipeline.GetFilterContoursOutput()))
	{
    	cv::Rect r = cv::boundingRect(i);
    	std::cout << "Rect X=" << r.x << " Y=" << r.y << " W=" << r.width << " H=" << r.height << endl;
    	cv::rectangle(image, r, cv::Scalar(0xFF,0xFF,0xFF), 1 );
	}

    cv::namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Display Image", image );
    cv::waitKey(0);



	return 0;
}
