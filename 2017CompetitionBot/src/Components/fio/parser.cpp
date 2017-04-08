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
			lineNum++;
			trim(line);
			if(line.length()) {
				if(line[0] == '#') {
					std::cout << line << std::endl;
					continue;
				}
				if(!std::isalnum(line[0]) || std::isalpha(line[0])) {
					std::cout << "unexpected data line:"<<lineNum<<": should be double:" << line[0] << std::endl;
					break;
				}
				// there are non white space characters, start reading the doubles out of it
				std::stringstream thelinestream(line);
				while(!thelinestream.eof()) {
					double d;
					char ch = thelinestream.peek();
					if(!std::isalnum(ch) || std::isalpha(ch)) {
						std::cout << "unexpected data line"<<lineNum<<":" << ch << ": expected double" << std::endl;
						break;
					}
					thelinestream >> d;
					v.push_back(d);
					count++;
					while(!thelinestream.eof() && (std::isspace(thelinestream.peek()))) {
						thelinestream.get(ch);
					}
				}
				break;
			}
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "exception" << std::endl;
	}
	return count;
}

int AutoFileParser::readCommand(char &cmd)
{
	std::string line;
	cmd = '\0';
	while(!inStream.eof()) {
		std::getline(inStream, line);
		lineNum++;
		trim(line);
		if(line.length()) {
			if(line[0] == '#') {
				std::cout << line << std::endl;
				continue;
			}
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
	lineNum = 0;
}

