/*
 * AutoFile.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */

#ifndef SRC_COMPONENTS_AUTOFILE_H_
#define SRC_COMPONENTS_AUTOFILE_H_

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

class AutoFile {
private:
	std::ifstream inStream;
	//std::map<int, Operation> operationMap;
public:
	AutoFile(const char* file);
	int readVector(std::string &line, std::vector<double> &v);
};

#endif /* SRC_COMPONENTS_AUTOFILE_H_ */
