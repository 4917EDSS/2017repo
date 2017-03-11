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

	cout << "Starting..." << endl;

	MachineVisionThread();

	// Report Center X/Y
	struct MachineVisionData mvd;
	mvd = visionResults.getResults();






	return 0;
}
