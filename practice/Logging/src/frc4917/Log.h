/*
 * Log.h
 *
 *  Created on: Sep 8, 2017
 *      Author: Gaudets
 */

#ifndef SRC_LOG_H_
#define SRC_LOG_H_

#include <vector>
#include "LogOutput.h"

namespace frc4917 {

	class Log {
	private:
		std::vector<frc4917::LogOutput *> outputs;	// Where the log messages go
		unsigned long channelMask;					// Which log channels are active/inactive
	public:
		// Replace "chanX" with a meaningful name (up to 32 channels)
		// Important:  This is a list of bit masks, not IDs which is why they count the way they do (only one bit set at a time)
		static constexpr unsigned long ERRORS		= 0x00000001;		// For unexpected errors
		static constexpr unsigned long WARNINGS		= 0x00000002;		// For things that we should look at but that aren't critical
		static constexpr unsigned long ASSERTS		= 0x00000004;		// For sections of code that should never execute
		static constexpr unsigned long DEBUG		= 0x00000008;		// For general debugging (don't overuse, add new channels instead)
//		static constexpr unsigned long DRIVETRAIN	= 0x00000010;
//		static constexpr unsigned long VISION		= 0x00000020;
//		static constexpr unsigned long chan7		= 0x00000040;
//		static constexpr unsigned long chan8		= 0x00000080;

		Log();
		void addOutputPath(LogOutput *newOutput);
		void clearOutputPaths(void);
		unsigned long getChannelMask(void);
		void setChannelMask(unsigned long chanMask);
		void enableChannels(unsigned long chanMask);
		void disableChannels(unsigned long chanMask);
		void send(unsigned long channel, const char *fmt, ...);
		~Log();
	};
}


#endif /* SRC_LOG_H_ */
