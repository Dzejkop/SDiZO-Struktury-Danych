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

	TreeNode *root;						// Korze� drzewa
	int count;							// Ilo�� element�w w drzewie
	void removeTree(TreeNode * node);	// Usuwa drzewo o zadanym korzeniu (to mo�e by� subdrzewo)
	
	void rotateRight(TreeNode* node);	// Wykonuje obr�t w prawo zadanego elementu
	
	void rotateLeft(TreeNode * node);	// Wykonuje obr�t w lewo zadanego elementu
	
	void remove(int key);				// Usuwa element o zadanym kluczu z drzewa
	void add(int key);					// Dodaje element z zadan� warto�ci�
	
	void display(string tekxt1, string tekxt2, TreeNode * node);	// Wyswietla drzewo

	bool find(int key);		// Sprawdza czy dana warto�� znajduje si� w drzewie
	TreeNode* getNode(int key);			// Dost�p do elementu o zadanym kluczu
};

