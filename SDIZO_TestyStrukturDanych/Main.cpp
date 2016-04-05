#include "Array.h"
#include "List.h"
#include "Heap.h"
#include <iostream>
#include "Timer.h"
#include "TestingSuite.h"
#include "FileReader.h"
#include "Tree.h"

using namespace std;

Array * arr;
Heap * heap;
List * list;
Tree * tree;

FileReader * readFile() {
	char * filename = new char[256];
	cout << "Wpisz nazwe pliku: " << endl;
	cin >> filename;

	FileReader * fReader = new FileReader(filename);

	fReader->openAndRead();
	
	delete[] filename;
	return fReader;
}

Array * buildArrayFromFile() {
	
	FileReader * fReader = readFile();

	return new Array(fReader->getSize(), fReader->getNumbers());
}

List * buildListFromFile() {

	FileReader * fReader = readFile();

	return new List(fReader->getSize(), fReader->getNumbers());
}

Heap * buildHeapFromFile() {

	FileReader * fReader = readFile();

	return new Heap(fReader->getSize(), fReader->getNumbers());
}

Tree * buildTreeFromFile() {
	FileReader * fReader = readFile();

	return new Tree(fReader->getSize(), fReader->getNumbers());
}

bool isArrayBuilt() {
	if (arr == nullptr) {
		cout << "Tablica nie jest zbudowana!" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool isListBuilt() {
	if (list == nullptr) {
		cout << "Lista nie jest zbudowana!" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool isHeapBuilt() {
	if (heap == nullptr) {
		cout << "Kopiec nie jest zbudowany!" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool isTreeBuilt() {
	if (tree == nullptr) {
		cout << "Drzewo nie jest zbudowany!" << endl;
		return false;
	}
	else {
		return true;
	}
}

void displayArray() {
	int * values = arr->access();

	cout << "Tablica: " << endl;
	for (int i = 0; i < arr->getSize(); i++) {
		cout << values[i];
		if (i != arr->getSize() - 1) cout << ", ";
	}
	cout << endl;
}

void displayHeapNode(int i) {

	int * a = heap->getArray();
	int right = heap->getRightOf(i);
	int left = heap->getLeftOf(i);

	cout << "(";
	if (left < heap->getSize()) displayHeapNode(left);
	else cout << "#";

	cout << "-" << a[i] << "-";

	if (right < heap->getSize()) displayHeapNode(right);
	else cout << "#";
	cout << ")";
}

void displayHeap() {
	heap->display(" ", "-", 0);
}

void displayList() {
	int size = list->getSize();

	cout << "Lista: " << endl;
	for (int i = 0; i < size; i++) {
		cout << list->get(i);
		if (i != size - 1) cout << ", ";
	}
	cout << endl;
}

void displayTree() {
	tree->display(" ", "-", tree->root);
}

void arrayRoutine() {
	while (true) {
		cout << "Menu tablicy: " << endl << endl;
		cout << "Wybierz akcje: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyswietl." << endl;
		cout << "3. Dodaj wartosc." << endl;
		cout << "4. Usuñ wartosc." << endl;
		cout << "5. Znajdz wartosc." << endl;
		cout << "6. Wroc do glownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			arr = buildArrayFromFile();
		}
		else if (dec == '2' && isArrayBuilt()) {
			displayArray();
		}
		else if (dec == '3') {
			if (arr == nullptr) arr = new Array();

			cout << "Wpisz wartosc do dodania: " << endl;
			int value;
			cin >> value;
			arr->append(value);
		}
		else if (dec == '4' && isArrayBuilt()) {
			cout << "Wpisz indeks do usuniecia: " << endl;
			int index; cin >> index;
			if (index >= arr->getSize()) cout << "Indeks za duzy!" << endl;
			else arr->remove(index);
		}
		else if (dec == '5' && isArrayBuilt()) {
			cout << "Cout wpisz wartosc ktora chcesz wyszukac: " << endl;
			int value; cin >> value;
			if (arr->find(value))
				cout << "Wartosc jest w tablicy" << endl;
			else
				cout << "Wartosci nie ma w tablicy" << endl;
		}
		else if (dec == '6') {
			break;
		}

	}
}

void heapRoutine() {
	while (true) {
		cout << "Menu kopca: " << endl << endl;
		cout << "Wybierz akcje: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyswietl." << endl;
		cout << "3. Dodaj wartosc." << endl;
		cout << "4. Usuñ korzen." << endl;
		cout << "5. Znajdz wartosc." << endl;
		cout << "6. Wroc do glownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			heap = buildHeapFromFile();
		}
		else if (dec == '2' && isHeapBuilt()) {
			displayHeap();
		}
		else if (dec == '3') {
			if (heap == nullptr) heap = new Heap();

			cout << "Wpisz wartosc do dodania: " << endl;
			int value;
			cin >> value;
			heap->insert(value);
		}
		else if (dec == '4' && isHeapBuilt()) {
			heap->extractRoot();
		}
		else if (dec == '5' && isHeapBuilt()) {
			cout << "Cout wpisz wartosc ktora chcesz wyszukac: " << endl;
			int value; cin >> value;
			if (heap->find(value))
				cout << "Wartosc jest w kopcu" << endl;
			else
				cout << "Wartosci nie ma w kopcu" << endl;
		}
		else if (dec == '6') {
			break;
		}

	}
}

void listRoutine() {
	while (true) {
		cout << "Menu listy:" << endl << endl;
		cout << "Wybierz akcje: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyswietl." << endl;
		cout << "3. Dodaj wartosc." << endl;
		cout << "4. Usuñ wartosc." << endl;
		cout << "5. Znajdz wartosc." << endl;
		cout << "6. Wroc do glownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			list = buildListFromFile();
		}
		else if (dec == '2' && isListBuilt()) {
			displayList();
		}
		else if (dec == '3') {
			if (list == nullptr) list = new List();

			cout << "Wpisz wartosc do dodania: " << endl;
			int value;
			cin >> value;
			list->append(value);
		}
		else if (dec == '4' && isListBuilt()) {
			cout << "Wpisz wartosc do usuniecia: " << endl;
			int value;
			cin >> value;
			list->remove(value);
		}
		else if (dec == '5' && isListBuilt()) {
			cout << "Cout wpisz wartosc ktora chcesz wyszukac: " << endl;
			int value; cin >> value;
			if (list->find(value))
				cout << "Wartosc jest w liscie" << endl;
			else
				cout << "Wartosci nie ma w liscie" << endl;
		}
		else if (dec == '6') {
			break;
		}

	}
}

void treeRoutine() {
	while (true) {
		cout << "Menu drzewa:" << endl << endl;
		cout << "Wybierz akcje: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyswietl." << endl;
		cout << "3. Dodaj wartosc." << endl;
		cout << "4. Usuñ wartosc." << endl;
		cout << "5. Znajdz wartosc." << endl;
		cout << "6. Wroc do glownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			tree = buildTreeFromFile();
		}
		else if (dec == '2' && isTreeBuilt()) {
			displayTree();
		}
		else if (dec == '3') {
			if (tree == nullptr) tree = new Tree();

			cout << "Wpisz wartosc do dodania: " << endl;
			int value;
			cin >> value;
			tree->add(value);
		}
		else if (dec == '4' && isTreeBuilt()) {
			cout << "Wpisz wartosc do usuniecia: " << endl;
			int value;
			cin >> value;
			tree->remove(value);
		}
		else if (dec == '5' && isTreeBuilt()) {
			cout << "Cout wpisz wartosc ktora chcesz wyszukac: " << endl;
			int value; cin >> value;
			if (tree->find(value))
				cout << "Wartosc jest w drzewie" << endl;
			else
				cout << "Wartosci nie ma w drzewie" << endl;
		}
		else if (dec == '6') {
			break;
		}

	}
}

void cleanup() {
	if (arr != nullptr) delete arr;
	if (list != nullptr) delete list;
	if (heap != nullptr) delete heap;
	if (tree != nullptr) delete tree;
}

void mainMenu() {
	while (true) {
		cout << "Wybierz strukture: " << endl;
		cout << "1. Lista." << endl;
		cout << "2. Kopiec." << endl;
		cout << "3. Tablica." << endl;
		cout << "4. Drzewo czerwono czarne." << endl;
		cout << "Lub" << endl;
		cout << "5. Zamknij program." << endl;

		char a; cin >> a;

		if (a == '1') listRoutine();
		if (a == '2') heapRoutine();
		if (a == '3') arrayRoutine();
		if (a == '4') treeRoutine();
		if (a == '5') break;
	}
}

int main() {
	mainMenu();
	cleanup();
	return 0;
}