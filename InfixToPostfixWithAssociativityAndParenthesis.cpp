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
	else {
		return 0;
	}
}

int isOperator(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return 1;
	}
	else {
		return 0;
	}
}

//infix to postfix conversion with associativity and parenthesis
char* InToPost(char* infix) {
	int len = strlen(infix);
	char* postfix = new char[len + 1];
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		if (isOperator(infix[i])) {
			while (top != NULL && pre(top->data) >= pre(infix[i])) {
				postfix[j++] = pop();
			}
			push(infix[i]);
		}
		else if (infix[i] == '(') {
			push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (top != NULL && top->data != '(') {
				postfix[j++] = pop();
			}
			pop(); // pop the '('
		}
		else {
			postfix[j++] = infix[i];
		}
		i++;
	}
	while (top != NULL) {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	return postfix;
}


int main()
{
	char* infix = "a+b*(c^d-e)^(f+g*h)-i";
	char* postfix = InToPost(infix);
	cout << "Postfix: " << postfix << endl;
	
	return 0;
}