#include "StackLL.h"
#include <iostream>

class Stack::Node {
	public:
		int data = 0;
		Node* link = nullptr;
};

int Stack::size() {
	return num_elements;
}

void Stack::push(int val) {
	Node* newPtr = new Node{val};

	if (num_elements == 0) {
		newPtr->link = frontPtr;
		frontPtr = newPtr;
	} else {
		Node* tmpPtr = frontPtr;
		newPtr->link = tmpPtr;
		frontPtr = newPtr;
	}
	num_elements++;
}

void Stack::pop() {
	Node* delPtr = frontPtr;
	frontPtr = delPtr->link;
	delete delPtr;
	num_elements--;
}

int Stack::top() {
	return frontPtr->data;
}

void Stack::clear() {
	while (num_elements > 0)
		pop();
}

Stack::~Stack() {
	clear();
}
