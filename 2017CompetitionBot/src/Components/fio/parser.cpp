/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include "parser.h"
#include <ctype.h>

void AutoFileParser::trim(std::string &str)
{
	for (std::string::size_type i = str.length() - 1; i >= 0; i--)
	{
	    if(std::isspace(str[i])) {
	    	str.erase(i,1);
	    }
	    else {
	    	break;
	    }
	}
	while (str.length() && std::isspace(str[0]))
	{
	    str.erase(0,1);
	}
}

int AutoFileParser::readVector(std::vector<double> &v)
{
	std::string line;
	int count = 0;
	try {
		while(!inStream.eof()) {
			std::getline(inStream, line);
			trim(line);
			if(line.length()) {
				// there are non white space characters, start reading the doubles out of it
				std::stringstream thelinestream(line);
				while(!thelinestream.eof()) {
					double d;
					thelinestream >> d;
					v.push_back(d);
					count++;
				}
			}
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return count;
}

int AutoFileParser::readCommand(char &cmd)
{
	std::string line;
	cmd = '\0';
	while(!inStream.eof()) {
		std::getline(inStream, line);
		trim(line);
		if(line.length()) {
			if(std::isalpha(line[0])) {
				cmd = line[0];
				return 0;
			}
		}
	}
	return -1;
}

AutoFileParser::AutoFileParser(std::ifstream &stream)
: inStream(stream) {
}

int AutoFileParser::parseFile(void)
{
	int operationCount = 0;
	char cmd;
	while(!readCommand(cmd)) {
		switch(cmd) {
			case 's':
				//operationMap[count] = new SilkyOperation();
				std::vector<double> left;
				std::vector<double> right;
				int leftCount = readVector(left);
				int rightCount = readVector(right);
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
