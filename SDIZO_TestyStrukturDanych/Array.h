#pragma once
class Array
{
private:
	int * intArray;
	int size;
public:
	Array();
	Array(int size, int * values);

	// Dodaje warto�� na pocz�tek
	void push(int val);

	// Dodaje warto�� na koniec
	void append(int val);

	// Dodaje warto�� na zadanej pozycji
	void add(int val, int position);

	// Usuwa warto�� z zadanej pozycji
	void remove(int position);

	// Usuwa warto�� z pocz�tku
	void shrink();

	// Usuwa warto�� z ko�ca
	void pop();

	// Dost�p bezpo�redni do tablicy
	int*  access();

	// Rozmiar
	int getSize();

	// Wyszukuje warto��
	bool find(int n);

	~Array();
};

