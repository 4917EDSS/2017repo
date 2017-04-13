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
#include "Commands/OpenGearFlapsCmd.h"
#include "Commands/SilkyRotateCmd.h"

AutoFile::AutoFile(const char* file)
: parser(inStream)
{
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}
}

Command* AutoFile::readCummulativeSilky(bool redIncluded)
{
	std::vector<double> leftBlue;
	std::vector<double> rightBlue;
	std::vector<double> leftRed;
	std::vector<double> rightRed;

	int leftBlueCount = parser.readVector(leftBlue);
	int rightBlueCount = parser.readVector(rightBlue);
	int leftRedCount = 0;
	int rightRedCount = 0;


	if(leftBlueCount != 0 && leftBlueCount == rightBlueCount) {
		if(redIncluded) {
			leftRedCount = parser.readVector(leftRed);
			rightRedCount = parser.readVector(rightRed);

			if(leftRedCount != 0 && leftRedCount == rightRedCount) {
				return new SilkyDriveCmd(leftBlue, rightBlue, leftRed, rightRed);
			} else {
				std::cout << "*** FAILED *** Not the same number of segments cummulative" << std::endl;
				return NULL;
			}
		} else {
				return new SilkyDriveCmd(leftBlue, rightBlue);
		}
	} else {
		std::cout << "*** FAILED *** Not the same number of segments cummulative" << std::endl;
		return NULL;
	}
}

Command* AutoFile::readDifferentialSilky(bool redIncluded)
{
	std::vector<double> leftBlue;
	std::vector<double> rightBlue;
	std::vector<double> leftRed;
	std::vector<double> rightRed;
	int leftCountBlue = parser.readVector(leftBlue);
	int rightCountBlue = parser.readVector(rightBlue);
	int leftCountRed = 0;
	int rightCountRed = 0;

	if(leftCountBlue != 0 && leftCountBlue == rightCountBlue) {
		for(int i = 1; i < leftCountBlue; i++) {
			leftBlue[i] += leftBlue[i-1];
			rightBlue[i] += rightBlue[i-1];
		}
		if(redIncluded) {
			leftCountRed = parser.readVector(leftRed);
			rightCountRed = parser.readVector(rightRed);
			if(leftCountRed != 0 && leftCountRed == rightCountRed) {
				for(int i = 1; i < leftCountRed; i++) {
					leftRed[i] += leftRed[i-1];
					rightRed[i] += rightRed[i-1];
				}
				return new SilkyDriveCmd(leftBlue, rightBlue, leftRed, rightRed);
			} else {
				std::cout << "*** FAILED *** Not the same number of segments differential" << std::endl;
				return NULL;
			}
		} else {
			return new SilkyDriveCmd(leftBlue, rightBlue);
		}
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

Command* AutoFile::readDriveStraight(bool redIncluded) {
	std::vector<double> parametersBlue;
	std::vector<double> parametersRed;
	double blueDistance;
	double redDistance;
	if(parser.readVector(parametersBlue) != 0) {
		blueDistance = parametersBlue[0];
	} else {
		return NULL;
	}
	if(redIncluded) {
		if(parser.readVector(parametersRed) != 0) {
			redDistance = parametersRed[0];
		} else {
			return NULL;
		}
		return new AHRSDriveStraightCmd(blueDistance, redDistance);
	} else {
		return new AHRSDriveStraightCmd(blueDistance);
	}
}

Command* AutoFile::readShoot() {
	return new ShootCmdGrp();
}

Command* AutoFile::readSpinUp() {
	return new SpinUpCmd(BOILER_SHOT_SHOOTER_SPEED);
}

Command* AutoFile::readGearFlaps(bool open) {
	return new OpenGearFlapsCmd(open);
}

Command* AutoFile::readSilkyRotate() {
	std::vector<double> params;
	if(parser.readVector(params) != 0) {
		return new SilkyRotateCmd(params[0]);
	} else {
		return NULL;
	}
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
				cb = readCummulativeSilky();
				break;
			case 'S':
				cb = readCummulativeSilky(true);
				break;
			//Differential Silky
			case 'd':
				cb = readDifferentialSilky();
				break;
			case 'D':
				cb = readDifferentialSilky(true);
				break;
			//Wait
			case 'w':
			case 'W':
				cb = readWait();
				break;
			//Linear ie. drive straight
			case 'l':
				cb = readDriveStraight();
			case 'L':
				cb = readDriveStraight(true);
				break;
			//FIRE!!!
			case 'f':
			case 'F':
				cb = readShoot();
				break;
			//Spin UP
			case 'u':
			case 'U':
				cb = readSpinUp();
				break;
			case 'g':
				cb = readGearFlaps(false);
			case 'G':
				cb = readGearFlaps(true);
				break;
			case 'r':
			case 'R':
				cb = readSilkyRotate();
				break;
			case '#':
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
