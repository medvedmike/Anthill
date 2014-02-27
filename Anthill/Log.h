#pragma once
#include <string>

enum LogLevel
{
	ALL = 1,
	DEBUG = 2,
	ERROR = 3,
	NONE = 4
};

class Log
{
private:
	static LogLevel level;
	Log();
public:
	static void Init();
	static void SetLevel(LogLevel _level);
	static void Message(const std::string message);
	static void Debug(const std::string message);
	static void Error(const std::string message);
};

