#pragma once
struct Node;

class List
{
private:
	Node * head;
	Node * tail;
	int size;
	
	// Inicjalizacja z zadan� warto�ci�
	void initializeWith(int val);

	// Dost�p do elementu
	Node * getNode(int i);
public:
	List();
	List(int size, int * values);

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

	// Rozmiar listy
	int getSize();

	// Dost�p do warto�ci o zadanym indeksie
	int get(int i);

	// Wyszukuje zadan� warto��
	bool find(int n);

	~List();
};