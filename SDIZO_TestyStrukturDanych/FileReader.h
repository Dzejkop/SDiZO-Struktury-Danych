#pragma once

#include <fstream>
#include <string>
#include <sstream>

class FileReader
{
private:
	char * filename;
	int * numbers;
	int size;
public:
	FileReader(char * filename);

	void openAndRead();
	int getSize();
	int * getNumbers();

	~FileReader();
};

