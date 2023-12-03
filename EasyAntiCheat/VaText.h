#pragma once

#define VA_TEXT_BUFFER_MAX 1024 * 8

namespace Utility
{
	class VaText
	{
	private:
		static char m_charBuffer[];
	public:
		//__forceinline VaText(const char* format, Args ... args);
		template<typename... Args>
		__forceinline VaText(const char* format, Args ... args);

		operator const char* () {
			return m_charBuffer;
		}

		__forceinline ~VaText()
		{
			ZeroMemory(m_charBuffer, VA_TEXT_BUFFER_MAX);
		}

		//operator std::string () {
		//	return m_charBuffer;
		//}
	};

	template<typename ...Args>
	__forceinline VaText::VaText(const char* format, Args ...args)
	{
		::snprintf(m_charBuffer, VA_TEXT_BUFFER_MAX, format, args...);
	}

#define va(fmt, ...) VaText(fmt, __VA_ARGS__)
}