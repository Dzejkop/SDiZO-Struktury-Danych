#include "Array.h"

Array::Array()
{
	intArray = new int[0];
	size = 0;
}

Array::Array(int size, int * values)
{
	this->size = size;

	intArray = new int[size];

	for (int i = 0; i < size; i++) {
		intArray[i] = values[i];
	}
}

void Array::push(int val)
{
	int * newArray = new int[size + 1];
	newArray[0] = val;

	for (int i = 0; i < size; i++) {
		newArray[i + 1] = intArray[i];
	}

	delete[] intArray;

	// Update internal variables
	size++;
	intArray = newArray;
}

void Array::append(int val)
{
	int * newArray = new int[size + 1];
	newArray[size] = val;

	for (int i = 0; i < size; i++) {
		newArray[i] = intArray[i];
	}

	delete[] intArray;

	// Update internal variables
	size++;
	intArray = newArray;
}


void Array::add(int val, int position)
{
	int * newArray = new int[size + 1];
	newArray[position] = val;

	for (int i = 0; i < size+1; i++) {
		if(i < position)
			newArray[i] = intArray[i];
		if(i > position)
			newArray[i] = intArray[i-1];
	}

	delete[] intArray;

	// Update internal variables
	size++;
	intArray = newArray;
}

void Array::remove(int position)
{
	int * newArray = new int[size - 1];

	for (int i = 0; i < size-1; i++) {
		if (i < position)
			newArray[i] = intArray[i];
		if (i >= position)
			newArray[i] = intArray[i + 1];
	}

	delete[] intArray;
	size--;
	intArray = newArray;
}

void Array::shrink()
{
	int * newArray = new int[size - 1];

	for (int i = 1; i < size; i++) {
		newArray[i-1] = intArray[i];
	}

	delete[] intArray;
	size--;
	intArray = newArray;
}

void Array::pop()
{
	int * newArray = new int[size - 1];

	for (int i = 0; i < size - 1; i++) {
		newArray[i] = intArray[i];
	}

	delete[] intArray;
	size--;
	intArray = newArray;
}

int * Array::access()
{
	return this->intArray;
}

int Array::getSize()
{
	return this->size;
}

bool Array::find(int n)
{
	for (int i = 0; i < size; i++) {
		if (n == intArray[i]) return true;
	}
	return false;
}

Array::~Array()
{
	delete[] intArray;
}
