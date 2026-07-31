#include "Stack.h"
using namespace std;

struct Node {
	char data;
	Node* next;
}*top=NULL;

void push(char x) {
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

char pop() {
	char x = -1;
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	else {
		Node* t = top;
		top = top->next;
		x = t->data;
		delete t;
	}
	return x;
}

int isBalanced(char* exp) {
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '(') {
			push(exp[i]);
		}
		else if (exp[i] == ')') {
			if (top == NULL) {
				return 0;
			}
			pop();
		}
	}
	return top == NULL ? 1 : 0;
}

int main()
{
	char* exp = "((a+b)*(c-d)))";
	cout << exp << " is " << (isBalanced(exp) ? "Balanced" : "Not Balanced") << endl;
	return 0;
}