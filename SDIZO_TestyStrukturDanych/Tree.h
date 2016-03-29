#pragma once

enum Color {
	BLACK, RED
};

struct TreeNode {
	TreeNode(int value, Color color, TreeNode* parent, TreeNode* right, TreeNode* left);
	TreeNode * parent;
	TreeNode * right;
	TreeNode * left;
	int value;
	Color color;
};

class Tree
{
private:
	TreeNode * guard;
	TreeNode * root;
	int size;

	//void insert(TreeNode * at, int value);
	void removeRoot();

	void insertCase1(TreeNode * n);
	void insertCase2(TreeNode * n);
	void insertCase3(TreeNode * n);
	void insertCase4(TreeNode * n);
	void insertCase5(TreeNode * n);

	void deleteOneChild(TreeNode * n);

	void deleteCase1(TreeNode * n);
	void deleteCase2(TreeNode * n);
	void deleteCase3(TreeNode * n);
	void deleteCase4(TreeNode * n);
	void deleteCase5(TreeNode * n);
	void deleteCase6(TreeNode * n);

	void replace(TreeNode * a, TreeNode * b);

	TreeNode* siblingOf(TreeNode * n);
	TreeNode* grandparentOf(TreeNode * n);
	TreeNode* uncleOf(TreeNode * n);
	TreeNode* nodeWithValue(int value);
	TreeNode* findLargestInLeftSubtree(TreeNode* at);

	void rotateRight(TreeNode * n);
	void rotateLeft(TreeNode * n);
public:
	Tree();

	void remove(int value);
	void insert(int value);
	bool find(int value);
	TreeNode * getRoot();

	~Tree();
};

