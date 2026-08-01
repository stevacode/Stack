#include "Stack.h"
#include <stdlib.h>
#include <cstring>
using namespace std;

struct Node {
	char data;
	Node* next;
}*top = NULL;

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

void Display() {
	Node* p = top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
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

int pre(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	return 0;
}

int isOperand(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return 0;
	}
	return 1;
}

char* InToPost(char* infix) {
	int i = 0, j = 0;
	char* postfix = new char[strlen(infix) + 1];
	while (infix[i] != '\0') {
		if (isOperand(infix[i])) {
			postfix[j++] = infix[i++];
		}
		else {
			if (top == NULL || pre(infix[i]) > pre(top->data)) {
				push(infix[i++]);
			}
			else {
				postfix[j++] = pop();
			}
		}
	}
	while (top != NULL) {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	return postfix;
}

int main()
{
	char* infix = "a+b*c-d/e";
	push('#'); // Sentinel value to mark the bottom of the stack
	char* postfix = InToPost(infix);
	cout << "Postfix: " << postfix << endl;
	delete[] postfix;

	return 0;
}