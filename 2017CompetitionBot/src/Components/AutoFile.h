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
#include "Commands/Command.h"

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
 * Note on commands:
 *  - Lowercase commands involving silky tune for blue and mirror for red.
 *  - Uppercase commands involving silky take 4 parameters and tune for blue and red.
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
 * W - Wait: wait
 * W Parameter 1 double time (s)
 * L - Linear: straight line.
 * L Parameter 1 distance to travel mm
 * F - Fire aka shoot
 * U - Spinup
 * G - Gearflaps
 * G lowercase is close / uppercase is open
 */

class AutoFile {
public:
	typedef std::pair<Command*, bool> Operation;
private:
	std::ifstream inStream;
	AutoFileParser parser;
	std::vector<Operation> commands;
	Command* readCummulativeSilky(bool redIncluded = false);
	Command* readDifferentialSilky(bool redIncluded = false);
	Command* readWait();
	Command* readDriveStraight();
	Command* readShoot();
	Command* readSpinUp();
	Command* readGearFlaps(bool open);
public:
	AutoFile(const char* file);
	std::vector<Operation>& readFile(void);
	int resetFile(const char *fileName);
};

#endif /* SRC_COMPONENTS_AUTOFILE_H_ */
