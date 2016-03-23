#pragma once
struct Node;

class List
{
private:
	Node * head;
	Node * tail;
	int size;
	
	// Inicjalizacja z zadan¹ wartoœci¹
	void initializeWith(int val);

	// Dostêp do elementu
	Node * getNode(int i);
public:
	List();
	List(int size, int * values);

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

	// Rozmiar listy
	int getSize();

	// Dostêp do wartoœci o zadanym indeksie
	int get(int i);

	// Wyszukuje zadan¹ wartoœæ
	bool find(int n);

	~List();
};