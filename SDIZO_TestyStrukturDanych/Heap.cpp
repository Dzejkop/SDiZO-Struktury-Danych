#include "Heap.h"

int Heap::getParentOf(int i)
{
	return (i-1) / 2;
}

int Heap::getLeftOf(int i)
{
	return (2 * i) + 1;
}

int Heap::getRightOf(int i)
{
	return (2 * i) + 2;
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

void Heap::display(string tekst1, string tekst2, int index)
{
	if (size == 0)
		cout << "Kopiec jest pusty" << endl;
	string tekst;

	string bottom = " $";
	bottom[0] = 192;
	bottom[1] = 196;
	string top = " -";
	top[0] = 218;
	top[1] = 196;
	string line = "  ";
	line[0] = 179;

	if (index <= size)
	{
		tekst = tekst1;
		if (tekst2 == top)
			tekst[tekst.length() - 2] = ' ';

		display(tekst + line, top, (2 * index) + 2);

		tekst = tekst.substr(0, tekst1.length() - 2);

		cout << tekst << tekst2 << data[index] << endl;

		tekst = tekst1;
		if (tekst2 == bottom)
			tekst[tekst.length() - 2] = ' ';
		display(tekst + line, bottom, (2 * index) + 1);
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
	if (size < 0) return;

	if (size == 0) return;

	if (size == 1) {
		size--;
		return;
	}

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

bool Heap::find(int value) {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) return true;
	}
	return false;
}

Heap::~Heap()
{
	delete[] data;
}
