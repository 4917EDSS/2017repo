/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include "AutoFile.h"
#include "fio/parser.h"
#include "../Commands/SilkyDriveCmd.h"
#include "Commands/WaitCommand.h"
#include "Commands/AHRSDriveStraightCmd.h"
#include "Commands/ShootCmdGrp.h"
#include "Commands/SpinUpCmd.h"

AutoFile::AutoFile(const char* file)
: parser(inStream)
{
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}
}

Command* AutoFile::readCummulativeSilky()
{
	//operationMap[count] = new SilkyOperation();
	std::vector<double> left;
	std::vector<double> right;
	int leftCount = parser.readVector(left);
	int rightCount = parser.readVector(right);
		std::cout << "Left: ";
		for(int i = 0; i < leftCount; i++) {
			std::cout << left[i] << " ";
		}
		std::cout << std::endl << "Right: ";
		for(int i = 0; i < rightCount; i++) {
			std::cout << right[i] << " ";
		}
		std::cout << std::endl;
	if(leftCount != 0 && leftCount == rightCount) {
		std::cout << "successful num segments:" << leftCount << std::endl;
		return new SilkyDriveCmd(left, right);
	} else {
		std::cout << "*** FAILED *** Not the same number of segments cummulative" << std::endl;
		return NULL;
	}
}

Command* AutoFile::readDifferentialSilky(void)
{
	//operationMap[count] = new SilkyOperation();
	std::vector<double> left;
	std::vector<double> right;
	int leftCount = parser.readVector(left);
	int rightCount = parser.readVector(right);
		std::cout << "Left: ";
		for(int i = 0; i < leftCount; i++) {
			std::cout << left[i] << " ";
		}
		std::cout << std::endl << "Right: ";
		for(int i = 0; i < rightCount; i++) {
			std::cout << right[i] << " ";
		}
		std::cout << std::endl;
	if(leftCount != 0 && leftCount == rightCount) {
		std::cout << "successful num differential segments:" << leftCount << std::endl;
		for(int i = 1; i < leftCount; i++) {
			left[i] += left[i-1];
			right[i] += right[i-1];
		}
		return new SilkyDriveCmd(left, right);
	} else {
		std::cout << "*** FAILED *** Not the same number of segments differential" << std::endl;
		return NULL;
	}
}

Command* AutoFile::readWait() {
	std::vector<double> parameters;
	if(parser.readVector(parameters) != 0) {
		double time = parameters[0];
		return new WaitCommand(time);
	} else {
		return NULL;
	}
}

Command* AutoFile::readDriveStraight() {
	std::vector<double> parameters;
	if(parser.readVector(parameters) != 0) {
		double distance = parameters[0];
		return new AHRSDriveStraightCmd(distance);
	} else {
		return NULL;
	}
}

Command* AutoFile::readShoot() {
	return new ShootCmdGrp();
}

Command* AutoFile::readSpinUp() {
	return new SpinUpCmd(BOILER_SHOT_SHOOTER_SPEED);
}

std::vector<AutoFile::Operation>& AutoFile::readFile(void)
{
	char cmd;
	bool parallel;
	while(!parser.readCommand(cmd, parallel)) {

		Command* cb = nullptr;

		switch(cmd) {
			//Normal silky
			case 's':
			case 'S':
				cb = readCummulativeSilky();
				break;
			//Differential Silky
			case 'd':
			case 'D':
				cb = readDifferentialSilky();
				break;
			//Wait
			case 'w':
			case 'W':
				cb = readWait();
				break;
			//Linear ie. drive straight
			case 'l':
			case 'L':
				cb = readDriveStraight();
				break;
			//FIRE!!!
			case 'f':
			case 'F':
				cb = readShoot();
				break;
			//SpinUP
			case 'u':
			case 'U':
				cb = readSpinUp();
				break;
			default:
				std::cout << "unexpected command:" << cmd << std::endl;
				break;
		}
		if(cb) {
			commands.push_back(Operation(cb, parallel));
		}
	}
	return commands;
}

int AutoFile::resetFile(const char *fileName)
{
	inStream.close();
	inStream.open(fileName);
	inStream.seekg(0);  // go back to beginning of the file.
	if(inStream.fail()) {
		std::cout << "File loading failed! : " << fileName << std::endl;
		return -1;
	}
	return 0;
}
