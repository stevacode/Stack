#include "Stack.h"
using namespace std;

struct Node {
	int data;
	Node* next;
}*top=NULL;

void push(int x) {
	Node* t = new Node;
	if (t == NULL) {
		cout << "Stack Overflow" << endl;
	}
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop() {
	int x = -1;
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	else {
		Node* t = top;
		x = t->data;
		top = top->next;
		delete t;
	}
	return x;
}

void Display() {
	Node* p = top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


int main()
{
	push(10);
	push(20);
	push(30);
	Display();
	cout << "Popped element: " << pop() << endl;
	return 0;
}