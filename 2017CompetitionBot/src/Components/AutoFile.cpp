/*
 * AutoFile.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Software
 */
#include "AutoFile.h"
#include "fio/parser.h"

AutoFile::AutoFile(const char* file) {
	inStream.open(file);
	if(inStream.fail()) {
		std::cout << "File loading failed!" << std::endl;
	}
}

int AutoFile::readFile(void)
{
	AutoFileParser parser(inStream);
	return parser.parseFile();
}
