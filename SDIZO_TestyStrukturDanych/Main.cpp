#include "Array.h"
#include "List.h"
#include "Heap.h"
#include <iostream>
#include "Timer.h"
#include "TestingSuite.h"
#include "FileReader.h"

using namespace std;

void arrayRoutine() {
	while (true) {
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartoœæ." << endl;
		cout << "4. Usuñ wartoœæ." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;
	}
}

void heapRoutine() {
	while (true) {
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartoœæ." << endl;
		cout << "4. Usuñ korzeñ." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;
	}
}

void listRoutine() {
	while (true) {
		cout << "Wybierz akcjê: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wyœwietl." << endl;
		cout << "3. Dodaj wartoœæ." << endl;
		cout << "4. Usuñ wartoœæ." << endl;
		cout << "5. ZnajdŸ wartoœæ." << endl;
		cout << "6. Wróc do g³ownego menu." << endl;

		char option; cin >> option;

		if (option == '6') break;
	}
}

int main() {

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
	return 0;
}