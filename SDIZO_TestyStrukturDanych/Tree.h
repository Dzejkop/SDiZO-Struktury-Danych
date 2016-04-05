#pragma once

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
	TreeNode();
	~TreeNode();
	TreeNode *parent, *left, *right;
	int key;
	string color;
};

class Tree
{
private:
	TreeNode guard;
	string topCorner, bottomCorner, line;
	string black;
	string red;
public:
	Tree();
	Tree(int size, int* values);
	~Tree();

	TreeNode *root;						// Korzeñ drzewa
	int count;							// Iloœæ elementów w drzewie
	void removeTree(TreeNode * node);	// Usuwa drzewo o zadanym korzeniu (to mo¿e byæ subdrzewo)
	
	void rotateRight(TreeNode* node);	// Wykonuje obrót w prawo zadanego elementu
	
	void rotateLeft(TreeNode * node);	// Wykonuje obrót w lewo zadanego elementu
	
	void remove(int key);				// Usuwa element o zadanym kluczu z drzewa
	void add(int key);					// Dodaje element z zadan¹ wartoœci¹
	
	void display(string tekxt1, string tekxt2, TreeNode * node);	// Wyswietla drzewo

	bool find(int key);		// Sprawdza czy dana wartoœæ znajduje siê w drzewie
	TreeNode* getNode(int key);			// Dostêp do elementu o zadanym kluczu
};

