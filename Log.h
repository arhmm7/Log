#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <string>

class Log
{
public:
	Log();
	~Log();

private:
	HANDLE hc; 
public:

	enum LogLevels
	{
		LogLevelError,
		LogLevelWarn,
		LogLevelInfo,
		LogLevelTrace
	};

	std::string getCurrentTime();
	void log(const char* inp , int lglvl); 
};
