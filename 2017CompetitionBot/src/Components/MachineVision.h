/*
 * MachineVision.h
 *
 *  Created on: Mar 9, 2017
 *      Author: egaudet
 */

#ifndef SRC_COMPONENTS_MACHINEVISION_H_
#define SRC_COMPONENTS_MACHINEVISION_H_

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
