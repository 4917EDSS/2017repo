/*
 * Log.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: Gaudets
 */
#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>
#include "LogOutput.h"


namespace frc4917 {
	// Children of the LogOutput class

	// ConsoleOutput goes to the Driver Station's dashboard.  You have to have it configured with
	// +Prints for the messages to display.
	ConsoleOutput::ConsoleOutput() {
		// Nothing special to do in the constructor
	}

	void ConsoleOutput::output(const char *fmt, ...) {
		va_list ap;
		va_start(ap, fmt);
		vfprintf(stdout, fmt, ap);
		va_end(ap);
	}

	ConsoleOutput::~ConsoleOutput() {
		// Nothing special to do in the destructor
	}

	// SyslogOutput goes to Linux's Syslog system.  Syslog can be configured to send log messages
	// to file and/or a remote machine.  In this case it's configured to send message to the team's
	// PC.  You need to use a client like Visual Syslog Server to receive the messages.
	int SyslogOutput::objectCount = 0;
	SyslogOutput::SyslogOutput(const char *ipAddress) {
		if(objectCount < 1) {
			// TODO:
			//  - Set the IP address in the syslog configuration file
			//  - Restart syslog to use the new address
			openlog("4917", LOG_NDELAY, LOG_USER);
		}
		objectCount++;
	}

	// Send the message to Syslog
	void SyslogOutput::output(const char *fmt, ...) {
		va_list ap;
		va_start(ap, fmt);
		syslog(LOG_DEBUG, fmt, ap);
		va_end(ap);
	}

	SyslogOutput::~SyslogOutput() {
		objectCount--;

		// Shutdown the syslog logging system if this is the last instance of SyslogOutput
		if(objectCount < 1)
		{
			closelog();
		}
	}
}





