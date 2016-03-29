#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"
#include <iostream>
#include "Timer.h"
#include "TestingSuite.h"
#include "FileReader.h"

using namespace std;

Array * arr;
Heap * heap;
List * list;

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

void displayArray() {
	int * values = arr->access();

	cout << "Tablica: " << endl;
	for (int i = 0; i < arr->getSize(); i++) {
		cout << values[i];
		if (i != arr->getSize() - 1) cout << ", ";
	}
	cout << endl;
}

void displayHeap() {
	
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

void displayNode(TreeNode* node) {

	if (node == nullptr) {
		cout << "#";
		return;
	}

	cout << "(";
	displayNode(node->left);
	cout << "-" << node->value << "-";
	displayNode(node->right);
	cout << ")";
}

void displayTree() {
	Tree * tree = new Tree();
	tree->insert(1);
	tree->insert(10);
	tree->insert(3);
	tree->insert(7);
	tree->insert(8);
	tree->insert(21);
	tree->insert(4);
	tree->insert(13);
	tree->insert(9);

	tree->remove(9);
	tree->remove(13);

	displayNode(tree->getRoot());
	cout << endl;

}

void arrayRoutine() {
	while (true) {
		cout << "Menu tablicy: " << endl << endl;
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartoœæ." << endl;
		cout << "4. Usuñ wartoœæ." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			arr = buildArrayFromFile();
		}
		else if (dec == '2' && isArrayBuilt()) {
			displayArray();
		}
		else if (dec == '3' && isArrayBuilt()) {
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
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartoœæ." << endl;
		cout << "4. Usuñ korzen." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			heap = buildHeapFromFile();
		}
		else if (dec == '2' && isHeapBuilt()) {
			displayArray();
		}
		else if (dec == '3' && isHeapBuilt()) {
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
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartosc." << endl;
		cout << "4. Usuñ wartosc." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;

		char dec; cin >> dec;
		cout << endl;

		if (dec == '1') {
			list = buildListFromFile();
		}
		else if (dec == '2' && isListBuilt()) {
			displayList();
		}
		else if (dec == '3' && isListBuilt()) {
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

void cleanup() {
	if (arr != nullptr) delete arr;
	if (list != nullptr) delete list;
	if (heap != nullptr) delete heap;
}

void mainMenu() {
	while (true) {
		cout << "Wybierz typ danych: " << endl;
		cout << "1. Lista." << endl;
		cout << "2. Kopiec." << endl;
		cout << "3. Tablica." << endl;
		cout << "Lub inn¹ opcje: " << endl;
		cout << "4. Zamknij program." << endl;

		char a; cin >> a;

		if (a == '1') listRoutine();
		if (a == '2') heapRoutine();
		if (a == '3') arrayRoutine();
		if (a == '4') break;
	}
}

void runTests() {
	int repeats = 1;

	TestingSuite * suite = new TestingSuite(10000, 255, true);

	TestResults results = suite->runAppendTestsForArray(repeats);

	cout << results.testHeader << endl;
	cout << "Avg. time: " << results.averageTimeInSeconds << "s " << endl;

	results = suite->runAppendTestsForHeap(repeats);

	cout << results.testHeader << endl;
	cout << "Avg. time: " << results.averageTimeInSeconds << "s " << endl;

	results = suite->runAppendTestsForList(repeats);

	cout << results.testHeader << endl;
	cout << "Avg. time: " << results.averageTimeInSeconds << "s " << endl;

	system("PAUSE");
}

int main() {
	//mainMenu();
	//runTests();
	displayTree();

	system("PAUSE");
	cleanup();
	return 0;
}