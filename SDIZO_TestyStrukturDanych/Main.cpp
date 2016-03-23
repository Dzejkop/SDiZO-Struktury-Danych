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
		cout << "Wybierz akcj�: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wy�wietl." << endl;
		cout << "3. Dodaj warto��." << endl;
		cout << "4. Usu� warto��." << endl;
		cout << "5. Znajd� warto��." << endl;
		cout << "6. Wr�c do g�ownego menu." << endl;
	}
}

void heapRoutine() {
	while (true) {
		cout << "Wybierz akcj�: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wy�wietl." << endl;
		cout << "3. Dodaj warto��." << endl;
		cout << "4. Usu� korze�." << endl;
		cout << "5. Znajd� warto��." << endl;
		cout << "6. Wr�c do g�ownego menu." << endl;
	}
}

void listRoutine() {
	while (true) {
		cout << "Wybierz akcj�: " << endl;
		cout << "1. Zbuduj z pliku." << endl;
		cout << "2. Wy�wietl." << endl;
		cout << "3. Dodaj warto��." << endl;
		cout << "4. Usu� warto��." << endl;
		cout << "5. Znajd� warto��." << endl;
		cout << "6. Wr�c do g�ownego menu." << endl;

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
		cout << "Lub inn� opcje: " << endl;
		cout << "4. Zamknij program." << endl;

		char a; cin >> a;

		if (a == '1') listRoutine();
		if (a == '2') heapRoutine();
		if (a == '3') arrayRoutine();
		if (a == '4') break;
	}
	return 0;
}