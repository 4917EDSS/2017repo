/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include "AutoFile.h"
#include "fio/parser.h"
#include "../Commands/SilkyDriveCmd.h"

AutoFile::AutoFile(const char* file)
: parser(inStream)
{
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}
}

CommandBase* AutoFile::readCummulativeSilky()
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

CommandBase* AutoFile::readDifferentialSilky(void)
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

std::vector<CommandBase*>& AutoFile::readFile(void)
{
	char cmd;
	while(!parser.readCommand(cmd)) {

		CommandBase* cb;

		switch(cmd) {
			case 's':
			case 'S':
				cb = readCummulativeSilky();
				if(cb) {
					commands.push_back(cb);
				}
				break;
			case 'd':
			case 'D':
				cb = readDifferentialSilky();
				if(cb) {
					commands.push_back(cb);
				}
				break;
			case 'l':
			case 'L':

			default:
				std::cout << "unexpected command:" << cmd << std::endl;
				break;
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
