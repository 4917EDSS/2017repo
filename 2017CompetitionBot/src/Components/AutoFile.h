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
#include "fio/parser.h"
#include "../CommandBase.h"

class AutoFile {
private:
	std::ifstream inStream;
	AutoFileParser parser;
	std::vector<CommandBase*> commands;
	CommandBase* readCummulativeSilky(void);
	CommandBase* readDifferentialSilky(void);
public:
	AutoFile(const char* file);
	std::vector<CommandBase*>& readFile(void);
	int resetFile(const char *fileName);
};

#endif /* SRC_COMPONENTS_AUTOFILE_H_ */
