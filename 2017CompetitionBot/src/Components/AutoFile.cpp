/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include "AutoFile.h"
#include "fio/parser.h"

AutoFile::AutoFile(const char* file)
: parser(inStream)
{
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}
}

int AutoFile::readCummulativeSilky()
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
		return 1;
	} else {
		std::cout << "*** FAILED *** Not the same number of segments cummulative" << std::endl;
		return 0;
	}
}

int AutoFile::readDifferentialSilky(void)
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
		return 1;
	} else {
		std::cout << "*** FAILED *** Not the same number of segments differential" << std::endl;
		return 0;
	}
}

int AutoFile::readFile(void)
{
	int operationCount = 0;
	char cmd;
	while(!parser.readCommand(cmd)) {
		switch(cmd) {
			case 's':
			case 'S':
				if(readCummulativeSilky()) {
					operationCount++;
				}
				break;
			case 'd':
			case 'D':
				if(readDifferentialSilky()) {
					operationCount++;
				}
				break;
			default:
				std::cout << "unexpected command:" << cmd << std::endl;
				break;
		}
	}
	return operationCount;
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
