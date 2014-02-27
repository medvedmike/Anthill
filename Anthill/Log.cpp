#include "Log.h"
#include <iostream>

LogLevel Log::level = ALL;

Log::Log()
{
	level = ALL;
}

void Log::Init()
{
	level = ALL;
}

void Log::SetLevel(LogLevel _level)
{
	level = _level;
}

void Log::Message(const std::string message)
{
	if (level <= ALL)
	{
		std::cout << "[MESSAGE|" << __DATE__ << "|" << __TIME__ << "] " << message << std::endl;
	}
}

void Log::Debug(const std::string message)
{
	if (level <= DEBUG)
	{
		std::cout << "[DEBUG|" << __DATE__ << "|" << __TIME__ << "] " << message << std::endl;
	}
}

void Log::Error(const std::string message)
{
	if (level <= ERROR)
	{
		std::cout << "[ERROR|" << __DATE__ << "|" << __TIME__ << "] " << message << std::endl;
	}
}