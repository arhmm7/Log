#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <string>

#include "Log.h"

#define _CRT_SECURE_NO_WARNINGS


Log::Log()
{
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	log("Initialized Log!", 2);
}
Log::~Log()
{
	log("Cleared Log!", 2);
}


std::string Log::getCurrentTime()
{
	auto cT = std::chrono::system_clock::now();
	auto cT_t = std::chrono::system_clock::to_time_t(cT);
	std::tm timeinfo;
#ifdef _MSC_VER
	localtime_s(&timeinfo, &cT_t);
#else
	localtime_r(&cT_t, &timeinfo);
#endif
	std::ostringstream oss;
	oss << std::put_time(&timeinfo, "%H:%M:%S");
	return oss.str();
}

void Log::log(const char* inp, int lglvl)
{
	if (lglvl == LogLevels::LogLevelError)
	{
		SetConsoleTextAttribute(hc, 0x0c);
		std::cout << " ( " << getCurrentTime() << " ) [ Error ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc, 0x0f);
	}
	else if (lglvl == LogLevels::LogLevelWarn)
	{
		SetConsoleTextAttribute(hc, 0x0e);
		std::cout << " ( " << getCurrentTime() << " ) [ Warning ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc, 0x0f);
	}
	else if (lglvl == LogLevels::LogLevelInfo)
	{
		SetConsoleTextAttribute(hc, 0x0a);
		std::cout << " ( " << getCurrentTime() << " ) [ Information ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc, 0x0f);
	}
	else if (lglvl == LogLevels::LogLevelTrace)
	{
		SetConsoleTextAttribute(hc, 0x0f);
		std::cout << " ( " << getCurrentTime() << " ) [ Message ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc, 0x0f);
	}
}

