/*
 * MachineVision.h
 *
 *  Created on: Mar 9, 2017
 *      Author: egaudet
 */

#ifndef SRC_COMPONENTS_MACHINEVISION_H_
#define SRC_COMPONENTS_MACHINEVISION_H_
#include <stdint.h>

const double PI  =3.141592653589793238463;

struct MachineVisionData {
	int x;
	int y;
	int centerX;
	int centerY;
	int horizontalSeparation;	// Num pixels between bounding box horizontally
	int averageHeight;			// Average height of the bounding boxes
	int heightDifference;  		// Left Height - Right Height
	int numCountoursFound;
	int imageWidth;
	int imageHeight;
	uint64_t frameTime;
	double frameTimeSeconds;
	double gripProcessingTime;
	double processingTime;
};

class MachineVisionResults {
private:
	bool firstSlotValid;
	struct MachineVisionData mvd[2];
public:
	MachineVisionResults();
	struct MachineVisionData getResults();
	void setResults(struct MachineVisionData newMvd);
};

// Function prototypes
void MachineVisionThread(void);

// Global variables
extern struct MachineVisionResults visionResults;


#endif /* SRC_COMPONENTS_MACHINEVISION_H_ */
