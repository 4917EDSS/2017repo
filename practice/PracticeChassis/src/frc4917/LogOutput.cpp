/*
 * LogOutputs.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: 4917
 */
#include <iostream>
#include <fstream>
#include <syslog.h>
#include "LogOutput.h"

#define SYSLOG_4917_CONFIG_FILE		"/etc/syslog-ng.d/4917syslog.conf"


namespace frc4917 {
	// Children of the LogOutput class

	// ConsoleOutput goes to the Driver Station's dashboard.  You have to have it configured with
	// +Prints for the messages to display.
	ConsoleOutput::ConsoleOutput() {
		// Nothing special to do in the constructor
	}

	void ConsoleOutput::output(const char *message) {
		std::cout << message;
	}

	ConsoleOutput::~ConsoleOutput() {
		// Nothing special to do in the destructor
	}

	// SyslogOutput goes to Linux's Syslog system.  Syslog can be configured to send log messages
	// to file and/or a remote machine.  In this case it's configured to send message to the team's
	// PC.  You need to use a client like Visual Syslog Server to receive the messages.
	int SyslogOutput::objectCount = 0;
	SyslogOutput::SyslogOutput(const std::string ipAddress) {
		if(objectCount < 1) {
			// Make sure that Syslog is sending messages to the correct IP address
			updateRemoteAddress(ipAddress);

			openlog("4917", LOG_NDELAY, LOG_USER);
		}
		objectCount++;
	}

	void SyslogOutput::updateRemoteAddress(std::string ipAddress) {
// Need to figure out how to write this file into an area owned by 'admin'
// For now, need to login to the roboRio as 'admin' and edit SYSLOG_4917_CONFIG_FILE manually to
// set the IP address of the computer that wants the syslog messages
#if 0
		// Need to make sure that syslog is sending messages to the right address.
		// Although we could just write the new configuration and restart the syslog service
		// every time, this is time consuming and could wear down flash.  Instead, check to see
		// if the current configuration matches the new configuration.  If it doesn't then
		// update it.

		// Generate new file
		std::string newContents;
		newContents =
				"# This file is an extension to /etc/syslog-ng/syslog-ng.conf\n"
				"\n"
				"destination remote_log_server {\n"
				"        udp(\"" + ipAddress + "\" port(514));\n"
				"        };\n"
				"\n"
				"log { source(src); destination(remote_log_server); };\n";

		// Retrieve existing file
		std::string fileContents;
		std::ifstream inFile(SYSLOG_4917_CONFIG_FILE, std::ios::in | std::ios::binary);
		if(inFile)
		{
			inFile.seekg(0, std::ios::end);
			fileContents.resize(inFile.tellg());
			inFile.seekg(0, std::ios::beg);
			inFile.read(&fileContents[0], fileContents.size());
			inFile.close();
		}

		// Compare and write if different
		if(newContents != fileContents) {
			std::ofstream outFile(SYSLOG_4917_CONFIG_FILE);
			if(outFile) {
				outFile << newContents;
				outFile.close();
			}
		}
#endif
	}

	// Send the message to Syslog
	void SyslogOutput::output(const char *message) {
		syslog(LOG_DEBUG, message);
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





