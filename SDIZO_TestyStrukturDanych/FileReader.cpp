#include "FileReader.h"

using namespace std;

FileReader::FileReader(char * filename)
{
	this->filename = filename;
	this->numbers = nullptr;
	this->size = 0;
}

void FileReader::openAndRead()
{
	fstream file;
	file.open(filename, ios::in);

	string line;

	getline(file, line, '\n');
	stringstream c(line);

	c >> size;

	numbers = new int[size];

	for (int i = 0; i < size; i++) {
		getline(file, line, '\n');
		stringstream c(line);
		c >> numbers[i];
	}

	file.close();
}

int FileReader::getSize()
{
	return size;
}

int * FileReader::getNumbers()
{
	return this->numbers;
}


FileReader::~FileReader()
{
	if (numbers != nullptr) delete[] numbers;
}
