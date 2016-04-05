#pragma once
#include <string>
#include <iostream>

using namespace std;

class Heap
{
private:
	int * data;

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

	// Funkcje dostêpu do pokrewnych elementów
	int getParentOf(int i);
	int getLeftOf(int i);
	int getRightOf(int i);

	// Dostêp bezpoœredni
	int * getArray();

	// Wyswietlanie
	void display(string t1, string t2, int index);

	// Rozmiar
	int getSize();

	// Przeszukuje kopiec w poszukiwaniu wartosci
	bool find(int value);

	~Heap();
};

