#pragma once
class Array
{
private:
	int * intArray;
	int size;
public:
	Array();
	Array(int size, int * values);

	// Dodaje wartoœæ na pocz¹tek
	void push(int val);

	// Dodaje wartoœæ na koniec
	void append(int val);

	// Dodaje wartoœæ na zadanej pozycji
	void add(int val, int position);

	// Usuwa wartoœæ z zadanej pozycji
	void remove(int position);

	// Usuwa wartoœæ z pocz¹tku
	void shrink();

	// Usuwa wartoœæ z koñca
	void pop();

	// Dostêp bezpoœredni do tablicy
	int*  access();

	// Rozmiar
	int getSize();

	// Wyszukuje wartoœæ
	bool find(int n);

	~Array();
};

