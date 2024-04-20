#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <string>

#include "Log.h"

Log::Log()
{
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	log("Initialized Log!",2);
}
Log::~Log()
{
	log("Cleared Log!",2);
}


std::string Log::getCurrentTime() 
	{
	    auto currentTime = std::chrono::system_clock::now();
	    auto currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	    auto timeinfo = std::localtime(&currentTime_t);
	    std::ostringstream oss;
	    oss << std::put_time(timeinfo, "%H:%M:%S");
	    return oss.str();
	}	

void Log::log(const char* inp , int lglvl)
{
	if(lglvl == LogLevels::LogLevelError)
	{
		SetConsoleTextAttribute(hc,0x0c);
		std::cout << " ( " << getCurrentTime() << " ) [ Error ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc,0x0f);
	}
	else if(lglvl == LogLevels::LogLevelWarn)
	{
		SetConsoleTextAttribute(hc,0x0e);
		std::cout << " ( " << getCurrentTime() << " ) [ Warning ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc,0x0f);
	}
	else if(lglvl == LogLevels::LogLevelInfo)
	{
		SetConsoleTextAttribute(hc,0x0a);
		std::cout << " ( " << getCurrentTime() << " ) [ Information ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc,0x0f);
	}
	else if(lglvl == LogLevels::LogLevelTrace)
	{
		SetConsoleTextAttribute(hc,0x0f);
		std::cout << " ( " << getCurrentTime() << " ) [ Message ] : " << inp << std::endl;
		SetConsoleTextAttribute(hc,0x0f);
	}	
}

