// Stack.cpp : Using array
//

#include "Stack.h"
using namespace std;

struct Stack {
	int size;
	int top;
	int* S;
};

void create(Stack* st) {
	cout << "Enter size of stack: " << endl;
	cin >> st->size; 
	st->top = -1;
	st->S = new int[st->size];
}

void Display(Stack st) {
	for (int i = st.top; i >= 0; i--) {
		cout << st.S[i] << " ";
	}
	cout << endl;
}

void push(Stack* st, int x) {
	if (st->top == st->size - 1) {
		cout << "Stack Overflow" << endl;
	}
	else {
		st->top++;
		st->S[st->top] = x;
	}
}

int pop(Stack* st) {
	int x = -1;
	if (st->top == -1) {
		cout << "Stack Underflow" << endl;
	}
	else {
		x = st->S[st->top--];
	}
	return x;
}

int peek(Stack st, int index) {
	int x = -1;
	if (st.top - index + 1 < 0) {
		cout << "Invalid Index" << endl;
	}
	else {
		x = st.S[st.top - index + 1];
	}
	return x;
}

int isEmpty(Stack st) {
	return st.top == -1;
}

int isFull(Stack st) {
	return st.top == st.size - 1;
}

int stackTop(Stack st) {
	if (!isEmpty(st)) {
		return st.S[st.top];
	}
	return -1;
}


int main()
{
	struct Stack st;
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	Display(st);
	//cout << "Popped element: " << pop(&st) << endl;
	//cout << "Popped element: " << pop(&st) << endl;
	//cout << "Popped element: " << pop(&st) << endl;
	//cout << "Popped element: " << pop(&st) << endl;
	//Display(st);

	cout << "Stack Top: " << stackTop(st) << endl;
	cout << "Is Stack Empty: " << isEmpty(st) << endl;
	cout << "Is Stack Full: " << isFull(st) << endl;
	cout << "Element at index 1: " << peek(st, 1) << endl;
	cout << "Element at index 2: " << peek(st, 2) << endl;
	cout << "Element at index 3: " << peek(st, 3) << endl;
	cout << "Element at index 4: " << peek(st, 4) << endl;
	cout << "Element at index 5: " << peek(st, 5) << endl;
	cout << "Element at index 6: " << peek(st, 6) << endl;
	cout << "Element at index 7: " << peek(st, 7) << endl;

	return 0;
}
