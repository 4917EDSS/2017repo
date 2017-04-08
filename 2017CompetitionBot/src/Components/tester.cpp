/*
 * tester.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: john
 */

#include <iostream>
#include "AutoFile.h"
#include "fio/parser.h"

int main(int argc, char *argv[])
{
	if(argc > 1) {
		AutoFile autoFile(argv[1]);
		std::cout << "numCmds successfully read:" << autoFile.readFile() << std::endl;
	}
	else {
		std::cout << "Usage: " << argv[0] << " <autoFile>" << std::endl;
		return -1;
	}
	return 0;
}
