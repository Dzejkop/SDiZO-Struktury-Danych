#include "Tree.h"

TreeNode::TreeNode(int value, Color color, TreeNode* parent, TreeNode* right, TreeNode* left) {
	this->parent = parent;
	this->right = right;
	this->left = left;
	this->value = value;
	this->color = color;
}

void Tree::insert(int value) {
	TreeNode * next;
	TreeNode * current;
	current = root;

	if (root == nullptr) {
		root = new TreeNode(value, RED, nullptr, nullptr, nullptr);
		insertCase1(root);
		return;
	}

	current = root;
	next = root;

	do {
		current = next;

		if (value < current->value) {
			next = current->left;
		}
		else {
			next = current->right;
		}
	} while (next != nullptr);

	next = new TreeNode(value, RED, current, nullptr, nullptr);
	if (value < current->value) {
		current->left = next;
	}
	else {
		current->right = next;
	}

	insertCase1(next);
}

void Tree::remove(int value) {
	TreeNode * n = nodeWithValue(value);

	if (n == nullptr) return;

	if (n->right != nullptr && n->left != nullptr) // Two children
	{
		TreeNode * l = findLargestInLeftSubtree(n);

		// Copy values
		replace(l, n);

		// Delete l
		deleteOneChild(l);
	}
	else {
		deleteOneChild(n);
	}
}

TreeNode * Tree::nodeWithValue(int value) {
	TreeNode * current = root;

	while (true) {
		if ((current->value == value) || (current == nullptr)) return current;

		if (value < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	return nullptr;
}

TreeNode* Tree::findLargestInLeftSubtree(TreeNode* at) {
	TreeNode * current = at->left;

	while(current->right != nullptr) {
		current = current->right;
	}

	return current;
}

TreeNode * Tree::getRoot() {
	return root;
}

void Tree::insertCase1(TreeNode* n) {
	if (n->parent == nullptr)
		n->color = BLACK;
	else
		insertCase2(n);
}

void Tree::insertCase2(TreeNode* n) {
	if (n->parent->color == BLACK)
		return;
	else
		insertCase3(n);
}

void Tree::insertCase3(TreeNode *n) {
	TreeNode * uncle = uncleOf(n);
	TreeNode * g = nullptr;
	if ((uncle != nullptr) && (uncle->color = RED)) {
		n->parent->color = BLACK;
		uncle->color = BLACK;
		g = grandparentOf(n);
		g->color = RED;
		insertCase1(g);
	}
	else {
		insertCase4(n);
	}
}

void Tree::insertCase4(TreeNode * n) {
	TreeNode * g = grandparentOf(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotateLeft(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotateRight(n->parent);
		n = n->right;
	}

	insertCase5(n);
}

void Tree::insertCase5(TreeNode * n) {
	TreeNode * g = grandparentOf(n);

	n->parent->color = BLACK;
	g->color = RED;

	if (n == n->parent->left)
		rotateRight(g);
	else
		rotateLeft(g);
}

void Tree::rotateLeft(TreeNode * n) {
	TreeNode * right = n->right;
	TreeNode * parent;

	if (right != nullptr) {
		parent = n->parent;
		n->right = right->left;

		if (n->right != nullptr) {
			n->right->parent = n;
		}

		right->left = n;
		right->parent = parent;
		n->parent = right;

		if (parent != nullptr) {
			if (parent->left == n) parent->left = right;
			else parent->right = right;
		}
		else
			root = right;
	}
}

void Tree::rotateRight(TreeNode * n) {
	TreeNode * left;
	TreeNode * parent;

	left = n->left;
	if (left != nullptr) {
		parent = n->parent;
		n->left = left->right;
		if (n->left != nullptr) {
			n->left->parent = n;
		}

		left->right = n;
		left->parent = parent;
		n->parent = left;

		if (parent != nullptr) {
			if (parent->left == n) parent->left = left;
			else parent->right = left;
		}
		else
			root = left;
	}
}

void Tree::replace(TreeNode * a, TreeNode * b) {
	int aValue = a->value;
	a->value = b->value;
	b->value = aValue;
}

TreeNode * Tree::siblingOf(TreeNode * n) {
	if ((n == nullptr) || (n->parent == nullptr))
		return nullptr;
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

TreeNode * Tree::grandparentOf(TreeNode * n) {
	if (n != nullptr && n->parent != nullptr)
		return n->parent->parent;
	else
		return nullptr;
}

TreeNode * Tree::uncleOf(TreeNode * n) {
	TreeNode * g = grandparentOf(n);

	if (g == nullptr)
		return nullptr;
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}

void Tree::deleteOneChild(TreeNode * n) {
	TreeNode * child = n->right == nullptr ? n->left : n->right;

	if (child == nullptr) {
		if (n->color == BLACK) {
			deleteCase1(n);

			delete n;
			n = nullptr;
			return;
		}
		else {

			TreeNode * parent = n->parent;
			bool r = parent->right == n;

			delete n;
			n = nullptr;

			if (r) parent->right = nullptr;
			else parent->left = nullptr;

			return;
		}
	}

	replace(n, child);

	if (n->color == BLACK) {
		if (child->color == BLACK)
			child->color = BLACK;
		else
			deleteCase1(child);
	}
	delete n;
	n = nullptr;
}

void Tree::deleteCase1(TreeNode * n) {
	if (n->parent != nullptr)
		deleteCase2(n);
}

void Tree::deleteCase2(TreeNode * n) {
	TreeNode * sibling = siblingOf(n);

	if (sibling->color == RED) {
		n->parent->color = RED;
		sibling->color = BLACK;

		if (n == n->parent->left)
			rotateLeft(n->parent);
		else
			rotateRight(n->parent);
	}
	deleteCase3(n);
}

void Tree::deleteCase3(TreeNode * n) {
	TreeNode * sibling = siblingOf(n);

	if ((n->parent->color == BLACK) &&
		(sibling->color == BLACK) &&
		(sibling->left->color == BLACK) &&
		(sibling->right->color == BLACK)) {
		sibling->color = RED;
		deleteCase1(n->parent);
	}
	else {
		deleteCase4(n);
	}
}

void Tree::deleteCase4(TreeNode * n) {
	TreeNode * sibling = siblingOf(n);

	if ((n->parent->color == BLACK) &&
		(sibling->color == BLACK) &&
		(sibling->left->color == BLACK) &&
		(sibling->right->color == BLACK)) {
		sibling->color = RED;
		n->parent->color = BLACK;
	}
	else {
		deleteCase5(n);
	}
}

void Tree::deleteCase5(TreeNode * n) {
	TreeNode * sibling = siblingOf(n);

	if (sibling->color == BLACK) {
		if ((n == n->parent->left) &&
			(sibling->right->color == BLACK) &&
			(sibling->left->color == RED)) {
			sibling->color = RED;
			sibling->left->color = BLACK;
			rotateRight(sibling);
		}
		else if ((n == n->parent->right) &&
			(sibling->left->color == BLACK) &&
			(sibling->right->color == RED)) {
			sibling->color = RED;
			sibling->right->color = BLACK;
			rotateLeft(sibling);
		}
	}
	deleteCase6(n);
}

void Tree::deleteCase6(TreeNode * n) {
	TreeNode * sibling = siblingOf(n);

	sibling->color = n->parent->color;
	n->parent->color = BLACK;

	if (n == n->parent->left) {
		sibling->right->color = BLACK;
		rotateLeft(n->parent);
	}
	else {
		sibling->left->color = BLACK;
		rotateRight(n->parent);
	}
}

Tree::Tree()
{
	size = 0;

	/*
	nullptr = new TreeNode(0, BLACK, nullptr, nullptr, nullptr);
	nullptr->parent = nullptr;
	nullptr->left = nullptr;
	nullptr->right = nullptr;
	*/

	root = nullptr;
}


Tree::~Tree()
{
}
