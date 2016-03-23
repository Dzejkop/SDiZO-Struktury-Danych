#pragma once

#include "Heap.h"
#include "Array.h"
#include "List.h"
#include <ctime>
#include <random>
#include "Timer.h"

struct TestResults {
	TestResults(char * header, int dataSize, double averageTmeInNano);
	char * testHeader;
	int dataSize;
	double averageTimeInNanoseconds;
	double averageTimeInSeconds;
};

class TestingSuite
{
private:
	int * randomData;
	int dataSize;
	int maxInt;
public:
	TestingSuite(int dataSize, int maxInt);

	void prepareTestData();
	TestResults runAppendTestsForArray(int repeats);
	TestResults runAppendTestsForList(int repeats);
	TestResults runAppendTestsForHeap(int repeats);

	~TestingSuite();
};