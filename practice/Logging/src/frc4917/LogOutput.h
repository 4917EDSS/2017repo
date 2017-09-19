/*
 * Log.h
 *
 *  Created on: Sep 8, 2017
 *      Author: Gaudets
 */

#ifndef SRC_LOGOUTPUT_H_
#define SRC_LOGOUTPUT_H_


namespace frc4917 {

	// Parent class for all output types
	class LogOutput {
	public:
		virtual void output(const char *fmt, ...) {}
		virtual ~LogOutput() {}
	};

	class ConsoleOutput : public LogOutput {
	public:
		ConsoleOutput();
		void output(const char *fmt, ...);
		~ConsoleOutput();
	};

	class SyslogOutput : public LogOutput {
	private:
		static int objectCount;
	public:
		SyslogOutput(const char *ipAddress);
		void output(const char *fmt, ...);
		~SyslogOutput();
	};

}


#endif /* SRC_LOGOUTPUT_H_ */
