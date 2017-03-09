/*
 * MachineVision.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: egaudet
 */

#include "MachineVision.h"

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


