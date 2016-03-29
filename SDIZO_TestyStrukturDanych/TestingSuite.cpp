#include "TestingSuite.h"

TestResults::TestResults(char * header, int dataSize, double averageTmeInNano) {
	this->testHeader = header;
	this->dataSize = dataSize;
	this->averageTimeInNanoseconds = averageTmeInNano;
	this->averageTimeInSeconds = averageTmeInNano / 1000000000;
}

TestingSuite::TestingSuite(int dataSize, int maxInt, bool randomize)
{
	srand(time(nullptr));	// Seed of time
	this->dataSize = dataSize;
	this->maxInt = maxInt;
	this->randomizeEachRepeat = randomize;
}

void TestingSuite::prepareTestData()
{
	if (randomData != nullptr) delete[] randomData;

	randomData = new int[dataSize];

	for (int i = 0; i < dataSize; i++) {
		randomData[i] = rand() % maxInt;
	}
}

TestResults TestingSuite::runAppendTestsForArray(int repeats)
{
	Timer timer;
	Array * arr;
	double avgTime = 0;
	for (int i = 0; i < repeats; i++) {
		timer = Timer();
		arr = new Array();
		if(randomizeEachRepeat) prepareTestData();
		
		timer.startTimer();
		for (int q = 0; q < dataSize; q++) {
			arr->append(randomData[q]);
		}
		timer.endTimer();

		avgTime += timer.getTimeInNanoseconds();

		delete arr;
	}

	avgTime = avgTime / (double)repeats;

	return TestResults("Array Append Test", dataSize, avgTime);
}

TestResults TestingSuite::runAppendTestsForList(int repeats)
{
	Timer timer;
	List * list;
	double avgTime = 0;
	for (int i = 0; i < repeats; i++) {
		timer = Timer();
		list = new List();
		if (randomizeEachRepeat) prepareTestData();
		
		timer.startTimer();
		for (int q = 0; q < dataSize; q++) {
			list->append(randomData[q]);
		}
		timer.endTimer();

		avgTime += timer.getTimeInNanoseconds();

		std::cout << "List time: " << timer.getTimeInNanoseconds() << std::endl;

		delete list;
	}

	avgTime = avgTime / (double)repeats;

	return TestResults("List Append Test", dataSize, avgTime);
}

TestResults TestingSuite::runAppendTestsForHeap(int repeats)
{
	Timer timer;
	Heap * heap;
	double avgTime = 0;
	for (int i = 0; i < repeats; i++) {
		timer = Timer();
		heap = new Heap();
		if (randomizeEachRepeat) prepareTestData();
		
		timer.startTimer();
		for (int q = 0; q < dataSize; q++) {
			heap->insert(randomData[q]);
		}
		timer.endTimer();

		avgTime += timer.getTimeInNanoseconds();

		delete heap;
	}

	avgTime = avgTime / (double)repeats;

	return TestResults("Heap Insert Test", dataSize, avgTime);
}


TestingSuite::~TestingSuite()
{
	if (randomData != nullptr) delete[] randomData;
}
