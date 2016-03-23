#pragma once
class Heap
{
private:
	int * data;

	// Funkcje dostêpu do pokrewnych elementów
	int getParentOf(int i);
	int getLeftOf(int i);
	int getRightOf(int i);

	// Naprawa kopca w górê
	void upHeap(int i);

	// Naprawa kopca w dó³
	void heapify(int i);

	int size;

	// Zamienia miejscami 2 wartoœci
	void swapValuesAt(int a, int b);
public:
	Heap();
	Heap(int size, int * values);

	// Wstawia wartoœæ do kopca
	void insert(int val);

	// Usuwa korzeñ
	void extractRoot();

	// Dostêp bezpoœredni
	int * getArray();

	// Rozmiar
	int getSize();

	~Heap();
};

