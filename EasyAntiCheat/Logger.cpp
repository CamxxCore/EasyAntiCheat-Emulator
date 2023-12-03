#include "pch.h"

namespace Utility {
	Logger::Logger() {
	}

	void Logger::Write( int logLevel, const char* format, ... ) const {

		char inBuf[4096] {};

		va_list va;
		va_start( va, format );
		vsprintf_s( inBuf, format, va );
		va_end( va );

		//auto str = va( "[LOG] %s\n", inBuf );

		OutputDebugStringA( inBuf );
	}

	Logger::~Logger() {

	}
}
