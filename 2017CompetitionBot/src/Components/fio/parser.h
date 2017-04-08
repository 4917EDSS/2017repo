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

/*
 * Format of input file
 * A command is a single letter on a separate line
 * A vector is a set of double values separated by white space on a single line
 * Blank lines will be ignored.  Lines beginning with # will be ignored
 *
 * Command 0
 * Command 0 Parameter 0
 * [Command 0 Parameter 1]
 * ...
 * [Command 0 Parameter N-1]
 * Command 1
 * Command 2 Parameter 0
 * [Command 2 Parameter 2]
 * ...
 * [Command Parameter N-1]
 * Command 2
 * ...
 * Command N - 1
 * Command N - 1 Parameter 0
 * [Command N - 1 Parameter 1]
 * <EOF>
 *
 * Commands:
 *
 * S - Silky Cumulative
 * S Parameter 0 Left Vector (cumulative totals)
 * double double double ... double
 * S Parameter 1 Right Vector (cumulative totals), (number of points must match left)
 * double double double ... double
 * D - Silky Deltas
 * D Parameter 0 Left Vector (Deltas from previous point)
 * double double ... double
 * D Parameter 1 Right Vector (Deltas from previous point), (number of points must match left)
 * double double ... double
 * L - Linear: straight line.
 * L Parameter 1 distance to travel
 */


class AutoFileParser{
private:
	int lineNum;
	std::ifstream &inStream;
	//std::map<int, Operation> operationMap;
	void trim(std::string &); // remove white space from front and back, handles empty strings
public:
	AutoFileParser(std::ifstream &stream);
	int readVector(std::vector<double> &v);
	int readCommand(char &cmd);
};

#endif /* SRC_COMPONENTS_FIO_PARSER_H_ */
