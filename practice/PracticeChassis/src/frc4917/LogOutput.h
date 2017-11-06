/*
 * LogOutput.h
 *
 *  Created on: Sep 8, 2017
 *      Author: 4917
 */

#ifndef SRC_LOGOUTPUT_H_
#define SRC_LOGOUTPUT_H_

#include <string>

namespace frc4917 {

	// Parent class for all output types
	class LogOutput {
	public:
		virtual void output(const char *message) {}
		virtual ~LogOutput() {}
	};

	class ConsoleOutput : public LogOutput {
	public:
		ConsoleOutput();
		void output(const char *message);
		~ConsoleOutput();
	};

	class SyslogOutput : public LogOutput {
	private:
		static int objectCount;
	public:
		SyslogOutput(const std::string ipAddress);
		void updateRemoteAddress(std::string ipAddress);
		void output(const char *message);
		~SyslogOutput();
	};

}


#endif /* SRC_LOGOUTPUT_H_ */
