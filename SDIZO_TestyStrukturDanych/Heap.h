#pragma once
class Heap
{
private:
	int * data;

	// Funkcje dost�pu do pokrewnych element�w
	int getParentOf(int i);
	int getLeftOf(int i);
	int getRightOf(int i);

	// Naprawa kopca w g�r�
	void upHeap(int i);

	// Naprawa kopca w d�
	void heapify(int i);

	int size;

	// Zamienia miejscami 2 warto�ci
	void swapValuesAt(int a, int b);
public:
	Heap();
	Heap(int size, int * values);

	// Wstawia warto�� do kopca
	void insert(int val);

	// Usuwa korze�
	void extractRoot();

	// Dost�p bezpo�redni
	int * getArray();

	// Rozmiar
	int getSize();

	~Heap();
};

