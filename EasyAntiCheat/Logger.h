#pragma once
#include <string>

#define LOG(x,...) g_logfile.Write(0, x, __VA_ARGS__);

namespace Utility {
	class Logger sealed {
	public:
		explicit Logger( std::string filename ) {}
		Logger();
		void Write( int logLevel, const char* format, ... ) const;
		~Logger();
	};

}

static Utility::Logger g_logfile;
