#pragma once
#include <string>
#include <iostream>

using namespace std;

class Heap
{
private:
	int * data;

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

	// Funkcje dost�pu do pokrewnych element�w
	int getParentOf(int i);
	int getLeftOf(int i);
	int getRightOf(int i);

	// Dost�p bezpo�redni
	int * getArray();

	// Wyswietlanie
	void display(string t1, string t2, int index);

	// Rozmiar
	int getSize();

	// Przeszukuje kopiec w poszukiwaniu wartosci
	bool find(int value);

	~Heap();
};

