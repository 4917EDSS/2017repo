/*
 * AutoFile.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */

#ifndef SRC_COMPONENTS_FIO_PARSER_H_
#define SRC_COMPONENTS_FIO_PARSER_H_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

class AutoFileParser{
private:
	int lineNum;
	std::ifstream &inStream;
	//std::map<int, Operation> operationMap;
	void trim(std::string &); // remove white space from front and back, handles empty strings
public:
	AutoFileParser(std::ifstream &stream);
	int readVector(std::vector<double> &v);
	int readCommand(char &cmd, bool &parallel);
};

#endif /* SRC_COMPONENTS_FIO_PARSER_H_ */
