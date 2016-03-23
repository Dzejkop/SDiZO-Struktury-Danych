#include "Timer.h"



Timer::Timer()
{
}

void Timer::startTimer()
{
	isDone = false;

	startTime = std::chrono::high_resolution_clock::now();

	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
}

void Timer::endTimer()
{
	isDone = true;

	endTime = std::chrono::high_resolution_clock::now();

	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
}

double Timer::getTimeInSeconds()
{
	if (isDone)
		return getTimeInNanoseconds() / 1000000000;
	else
		return 0;
}

double Timer::getTimeInNanoseconds()
{
	if (isDone)
		return (endTime - startTime).count();
	else
		return 0;
}

double Timer::getTimeInMicroseconds()
{
	if (isDone)
		return stop.QuadPart - start.QuadPart;
	else
		return 0;
}


Timer::~Timer()
{
}
