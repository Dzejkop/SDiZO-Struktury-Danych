#include "List.h"

struct Node {
	Node() {
		previous = nullptr;
		next = nullptr;
	}
	~Node() {

	}
	Node * previous;
	Node * next;
	int value;
};

void List::initializeWith(int val)
{
	head = new Node();
	tail = head;
	head->value = val;
	size=1;
}

Node* List::getNode(int i)
{
	if (head != nullptr && i >= 0 && i < size) {
		Node * node = head;
		for (int n = 0; n < i; n++) {
			node = node->next;
		}
		return node;
	}
	else {
		return nullptr;
	}
}

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::List(int size, int * values)
{
	Node * current;
	current = new Node();
	current->previous = nullptr;
	head = current;
	current->value = values[0];

	Node * temp;

	for (int i = 1; i < size; i++) {
		temp = new Node();
		current->next = temp;
		temp->previous = current;
		temp->value = values[i];

		current = temp;
	}

	tail = current;
	tail->next = nullptr;

	this->size = size;
}

void List::push(int val)
{
	if (head == nullptr) {
		initializeWith(val);
		return;
	}

	Node * newNode = new Node();	// New node previous to head
	newNode->value = val;			// Set value
	newNode->next = head;			// New points at head
	head->previous = newNode;		// Head points back at new

	head = newNode;					// Replace

	size++;
}

void List::append(int val)
{
	if (head == nullptr) {
		initializeWith(val);
		return;
	}

	Node * newNode = new Node();
	newNode->value = val;
	newNode->previous = tail;		// New points back at tail
	tail->next = newNode;			// Tail points at new

	tail = newNode;

	size++;
}

void List::add(int val, int position)
{
	if (head == nullptr) {
		initializeWith(val);
		return;
	}
	
	if (position < 0 || position >= size) return;

	if (position == 0) {
		push(val);
		return;
	}

	if (position == size - 1) {
		append(val);
		return;
	}

	Node * after = getNode(position);
	Node * before = after->previous;

	Node * newNode = new Node();
	newNode->value = val;

	before->next = newNode;
	newNode->previous = before;

	newNode->next = after;
	after->previous = newNode;

	size++;
}

void List::remove(int position)
{
	if (head == nullptr) return;
	if (position < 0 || position >= size) return;

	if (position == 0) {
		shrink();
		return;
	}
	if (position == size - 1) {
		pop();
		return;
	}

	Node * n = getNode(position);

	Node * previous = n->previous;
	Node * next = n->next;

	delete n;

	previous->next = next;
	next->previous = previous;

	size--;
}

void List::shrink()
{
	if (head == nullptr) return;

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node * n = head->next;
		delete head;
		n->previous = nullptr;
		head = n;
	}

	size--;
}

void List::pop()
{
	if (head == nullptr) return;

	if (tail->previous == nullptr) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node * n = tail->previous;
		delete tail;
		n->next = nullptr;
		tail = n;
	}

	size--;
}

int List::getSize()
{
	return this->size;
}


int List::get(int i)
{
	Node * n = getNode(i);
	if (n != nullptr)
		return n->value;

	else return -1;
}

bool List::find(int n)
{
	Node * node = head;
	for (int i = 0; i < size; i++) {
		if (node->value == n) return true;
		node = node->next;
	}
	return false;
}

List::~List()
{
	if (head == nullptr) return;
	Node * node = head;
	Node * swap;
	bool done = false;
	while (!done) {
		if (node != nullptr) {
			if (node->next != nullptr) {
				swap = node->next;
				delete node;
				node = swap;
			}
			else {
				delete node;
				done = true;
			}
		}
		else {
			done = true;
		}
	}
}