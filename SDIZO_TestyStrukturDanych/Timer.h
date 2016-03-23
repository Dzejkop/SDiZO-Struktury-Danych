#pragma once
#include <chrono>
#include <Windows.h>

using namespace std;

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
	bool isDone;
	LARGE_INTEGER start;
	LARGE_INTEGER stop;

public:
	Timer();
	void startTimer();
	void endTimer();
	double getTimeInSeconds();
	double getTimeInNanoseconds();
	double getTimeInMicroseconds();
	~Timer();
};

