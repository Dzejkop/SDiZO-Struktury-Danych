#include "Heap.h"

int Heap::getParentOf(int i)
{
	return i / 2;
}

int Heap::getLeftOf(int i)
{
	return 2 * i;
}

int Heap::getRightOf(int i)
{
	return (2 * i) + 1;
}

void Heap::upHeap(int i)
{
	int parent;
	while (true) {
		if (i == 0) break;

		parent = getParentOf(i);
		if (data[parent] < data[i]) {
			swapValuesAt(parent, i);
			i = parent;
		}
		else {
			break;
		}
	}
}

void Heap::heapify(int i)
{
	int max = i;
	int left = getLeftOf(i);
	int right = getRightOf(i);

	if (left <= size && data[left] > data[max])
		max = left;
	if (right <= size && data[right] > data[max])
		max = right;

	if (max != i) {
		swapValuesAt(i, max);
		heapify(max);
	}
}

void Heap::swapValuesAt(int a, int b)
{
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

Heap::Heap()
{
	data = new int[0];
}

Heap::Heap(int size, int * values) {
	for (int i = 0; i < size; i++) {
		this->insert(values[i]);
	}
}

void Heap::insert(int val)
{
	int * tempData = new int[size + 1];
	for (int i = 0; i < size; i++) {
		tempData[i] = data[i];
	}
	tempData[size] = val;
	delete[] data;
	data = tempData;
	size++;
	upHeap(size - 1);
}

void Heap::extractRoot()
{
	int * tempData = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		tempData[i] = data[i];
	}
	tempData[0] = data[size - 1];
	delete[] data;
	data = tempData;
	size--;
	heapify(0);
}


int * Heap::getArray()
{
	return this->data;
}

int Heap::getSize()
{
	return this->size;
}

Heap::~Heap()
{
	delete[] data;
}
