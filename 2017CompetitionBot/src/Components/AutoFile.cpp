/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include <Components/AutoFile.h>

AutoFile::AutoFile(const char* file) {
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}

	std::string line;
	int operationCount = 0;
	while(std::getline(inStream, line)) {
		switch(line[0]) {
			case 's':
				//operationMap[count] = new SilkyOperation();
				std::vector<double> left;
				std::vector<double> right;
				std::getline(inStream, line);
				int leftCount = readVector(line, left);
				std::getline(inStream, line);
				int rightCount = readVector(line, right);
				if(leftCount == rightCount) {
					std::cout << "Left: ";
					for(int i = 0; i < leftCount; i++) {
						std::cout << left[i] << " ";
					}
					std::cout << std::endl << " Right: ";
					for(int i = 0; i < rightCount; i++) {
						std::cout << right[i] << " ";
					}
					std::cout << std::endl;
				} else {
					std::cout << "Not the same" << std::endl;
				}
				break;
		}
	}

}

int AutoFile::readVector(std::string &line, std::vector<double> &v) {
	std::stringstream lineStream(line);
	int i = 0;
	while(!lineStream.eof()) {
		lineStream >> v[i];
		i++;
	}
	return i;
}
