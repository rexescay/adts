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

	if (num_elements < 1) {
		newPtr->link = frontPtr;
		frontPtr = newPtr;
	} else {
		Node* tmpPtr = frontPtr;
		int loc = 1;

		while (loc != num_elements) {
			tmpPtr = tmpPtr->link;
			loc++;
		}

		newPtr->link = tmpPtr->link;
		tmpPtr->link = newPtr;
	}

	num_elements++;
}

void Stack::pop() {
	Node* tmpPtr = frontPtr;
	int loc = 1;

	if (num_elements > 0) {
		while (loc != num_elements-1) {
			tmpPtr = tmpPtr->link;
			loc++;
		}

		Node* delPtr = tmpPtr->link;
		delete delPtr;
		tmpPtr->link = nullptr;
		num_elements--;
	}
}

int Stack::top() {
	Node* tmpPtr = frontPtr;
	int loc = 1;

	if (num_elements == 0) {
		return 0;
	}

	while (loc != num_elements) {
		tmpPtr = tmpPtr->link;
		loc++;
	}
	return tmpPtr->data;
}

void Stack::clear() {
	while (num_elements > 0)
		pop();
}

Stack::~Stack() {
	clear();
}
