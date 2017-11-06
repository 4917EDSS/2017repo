/*
 * Log.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: 4917
 */
#include <stdarg.h>
#include "Log.h"

#include <iostream>


namespace frc4917 {

	// The Log class
	Log::Log() {
		channelMask = 0;
	}

	// Add a new output path
	// Don't pass in a LogOutput class, pass in one of it's child classes.
	// Currently, ConsoleOutput and SyslogOutput are supported
	void Log::addOutputPath(LogOutput *newOutput) {
		outputs.emplace_back(newOutput);
	}

	// Remove all of the output paths
	void Log::clearOutputPaths(void) {
		outputs.clear();
	}

	// Returns the mask of currently-enabled channels
	unsigned long Log::getChannelMask(void) {
		return channelMask;
	}

	// Enable the channel or channels listed in chanMask and disable all the other ones
	// OR channels together (e.g. frc4917::Log::ERROR | frc4917::Log::WARNINGS)
	void Log::setChannelMask(unsigned long chanMask) {
		channelMask = chanMask;
	}

	// Enable the channel or channels listed in chanMask
	// OR channels together (e.g. frc4917::Log::ERROR | frc4917::Log::WARNINGS)
	void Log::enableChannels(unsigned long chanMask) {
			channelMask |= chanMask;
	}

	// Disable the channel or channels listed in chanMask
	// OR channels together (e.g. frc4917::Log::ERROR | frc4917::Log::WARNINGS)
	void Log::disableChannels(unsigned long chanMask) {
			channelMask &= ~chanMask;
	}

	// Send a message to all defined output on all enabled channels
	void Log::send(unsigned long channel, const char *fmt, ...) {
		// Only send if this channel is currently enabled
		if(channel & channelMask) {
			// Send this log message to all registered outputs
			for(auto curOut : outputs) {
				va_list ap;
				va_start(ap, fmt);
				vsnprintf( messageBuffer, MAX_MESSAGE_LEN, fmt, ap );
				curOut->output(messageBuffer);
				va_end(ap);
			}
		}
	}

	Log::~Log() {
		for (auto curOut : outputs) {
			delete curOut;
		}
		outputs.clear();
	}
}





