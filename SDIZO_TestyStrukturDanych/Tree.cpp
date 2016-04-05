#include "Tree.h"

Tree::Tree()
{
	topCorner = bottomCorner = line = "  ";
	topCorner[0] = 218; topCorner[1] = 196;
	bottomCorner[0] = 192; bottomCorner[1] = 196;
	line[0] = 179;
	black = "R";
	red = "B";
	guard.color = black;
	guard.parent = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;
	count = 0;
}

Tree::Tree(int size, int* values) {

	topCorner = bottomCorner = line = "  ";
	topCorner[0] = 218; topCorner[1] = 196;
	bottomCorner[0] = 192; bottomCorner[1] = 196;
	line[0] = 179;
	black = "R";
	red = "B";
	guard.color = black;
	guard.parent = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;
	count = 0;

	for (int i = 0; i < size; i++) {
		add(values[i]);
	}
}

Tree::~Tree()
{
	removeTree(root);
	count = 0;
}

void Tree::removeTree(TreeNode *node)
{
	if (node != &guard)
	{
		removeTree(node->left);
		removeTree(node->right);
		delete node;
	}
}

void Tree::rotateLeft(TreeNode* node)
{
	TreeNode * rightSon, *father;

	rightSon = node->right;
	if (rightSon != &guard)
	{
		father = node->parent;
		node->right = rightSon->left;
		if (node->right != &guard)
			node->right->parent = node;

		rightSon->left = node;
		rightSon->parent = father;
		node->parent = rightSon;

		if (father != &guard)
		{
			if (father->left == node) father->left = rightSon; else father->right = rightSon;
		}
		else root = rightSon;
	}
}
void Tree::rotateRight(TreeNode* node)
{
	TreeNode * leftSon, *father;

	leftSon = node->left;
	if (leftSon != &guard)
	{
		father = node->parent;
		node->left = leftSon->right;
		if (node->left != &guard)
			node->left->parent = node;

		leftSon->right = node;
		leftSon->parent = father;
		node->parent = leftSon;

		if (father != &guard)
		{
			if (father->left == node) father->left = leftSon; else father->right = leftSon;
		}
		else root = leftSon;
	}
}

void Tree::display(string text1, string text2, TreeNode * node)
{
	string text;
	if (count == 0) return;
	else if (node != &guard)
	{
		text = text1;
		if (text2 == topCorner)
			text[text.length() - 2] = ' ';
		display(text + line, topCorner, node->right);

		text = text.substr(0, text1.length() - 2);
		cout << text << text2 << node->color << ":" << node->key << endl;

		text = text1;
		if (text2 == bottomCorner)
			text[text.length() - 2] = ' ';
		display(text + line, bottomCorner, node->left);
	}
}
void Tree::add(int key)
{
	TreeNode *newNode, *uncle;

	newNode = new TreeNode;
	newNode->left = &guard;
	newNode->right = &guard;
	newNode->parent = root;
	newNode->key = key;
	if (newNode->parent == &guard) root = newNode;
	else
		while (true)
		{
			if (key < newNode->parent->key)
			{
				if (newNode->parent->left == &guard)
				{
					newNode->parent->left = newNode;
					break;
				}
				newNode->parent = newNode->parent->left;
			}
			if (key >= newNode->parent->key)
			{
				if (newNode->parent->right == &guard)

				{
					newNode->parent->right = newNode;
					break;
				}
				newNode->parent = newNode->parent->right;
			}
		}
	newNode->color = red;
	while ((newNode != root) && (newNode->parent->color == red))
	{
		if (newNode->parent == newNode->parent->parent->left)
		{
			uncle = newNode->parent->parent->right;

			if (uncle->color == red)
			{
				newNode->parent->color = black;
				uncle->color = black;
				newNode->parent->parent->color = red;
				newNode = newNode->parent->parent;
				continue;
			}

			if (newNode == newNode->parent->right)
			{
				newNode = newNode->parent;
				rotateLeft(newNode);
			}

			newNode->parent->color = black;
			newNode->parent->parent->color = red;
			rotateRight(newNode->parent->parent);
			break;
		}
		else
		{
			uncle = newNode->parent->parent->left;

			if (uncle->color == red)
			{
				newNode->parent->color = black;
				uncle->color = black;
				newNode->parent->parent->color = red;
				newNode = newNode->parent->parent;
				continue;
			}

			if (newNode == newNode->parent->left)
			{
				newNode = newNode->parent;
				rotateRight(newNode);
			}

			newNode->parent->color = black;
			newNode->parent->parent->color = red;
			rotateLeft(newNode->parent->parent);
			break;
		}

	}
	root->color = black;
	count++;
}
bool Tree::find(int key)
{
	TreeNode * node;
	bool doesExists = false;
	node = root;
	while ((node != &guard) && (node->key != key))
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	if (node == &guard) doesExists = false;
	else doesExists = true;
	return doesExists;
}

TreeNode* Tree::getNode(int key)
{
	TreeNode * node;
	node = root;
	while ((node != &guard) && (node->key != key))
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	if (node == &guard) return nullptr;
	return node;
}

void Tree::remove(int key)
{
	if (!find(key))
		return;
	else if (count == 0)
		return;
	else
	{
		TreeNode *toRemove, *uncle, *son;
		toRemove = getNode(key);
		if ((toRemove->left == &guard) || (toRemove->right == &guard)) {}
		else
		{
			if (toRemove != &guard)
			{
				if (toRemove->right != &guard)
				{
					if (toRemove->right != &guard)
					{
						while (toRemove->right->left != &guard)
							toRemove->right = toRemove->right->left;
					}
					toRemove = toRemove->right;
				}
				else
				{
					toRemove = toRemove->parent;
					while ((toRemove != &guard) && (toRemove == toRemove->right))
					{
						toRemove = toRemove;
						toRemove = toRemove->parent;
					}
				}
			}
			else
				toRemove = &guard;
		}

		if (toRemove->left != &guard)
			son = toRemove->left;
		else
			son = toRemove->right;

		son->parent = toRemove->parent;

		if (toRemove->parent == &guard)
			root = son;
		else if
			(toRemove == toRemove->parent->left) toRemove->parent->left = son;
		else
			toRemove->parent->right = son;

		if (toRemove != toRemove) toRemove->key = toRemove->key;

		if (toRemove->color == black)
			while ((son != root) && (son->color == black))
			{
				if (son == son->parent->left)
				{
					uncle = son->parent->right;

					if (uncle->color == red)
					{
						uncle->color == black;
						son->parent->color = red;
						rotateLeft(son->parent);
						uncle = son->parent->right;
					}

					if ((uncle->left->color == black) && (uncle->right->color == black))
					{
						uncle->color = red;
						son = son->parent;
						continue;
					}

					if (uncle->right->color == black)
					{
						uncle->left->color == black;
						uncle->color = red;
						rotateRight(uncle);
						uncle = son->parent->right;
					}
					uncle->color = son->parent->color;
					son->parent->color = black;
					uncle->right->color = black;
					rotateLeft(son->parent);
					son = root;
				}
				else
				{
					uncle = son->parent->left;

					if (uncle->color == red)
					{
						uncle->color = black;
						son->parent->color = red;
						rotateRight(son->parent);
						uncle = son->parent->left;
					}

					if ((uncle->left->color == black) && (uncle->right->color == black))
					{
						uncle->color = red;
						son = son->parent;
						continue;
					}

					if (uncle->left->color == black)
					{
						uncle->right->color == black;
						uncle->color = red;
						rotateLeft(uncle);
						uncle = son->parent->left;
					}

					uncle->color = son->parent->color;
					son->parent->color = black;
					uncle->left->color = black;
					rotateRight(son->parent);
					son = root;
				}
			}
		son->color = black;
		count--;
	}

}

TreeNode::TreeNode()
{
}

TreeNode::~TreeNode()
{
}
