#include "Stack.h"
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Stack
{
private:
	Node* top;
public:
	Stack() { top = nullptr; }
	void push(int x);
	int pop();
	int peek();
	void Display();
};

void Stack::push(int x)
{
	Node* temp = new (nothrow) Node();
	if (!temp)
	{
		cout << "\nHeap Overflow";
		exit(1);
	}
	temp->data = x;
	temp->next = top;
	top = temp;
}

int Stack::pop()
{
	if (top == nullptr)
	{
		cout << "\nStack Underflow";
		exit(1);
	}
	Node* temp = top;
	top = top->next;
	int popped = temp->data;
	delete temp;
	return popped;
}

void Stack::Display()
{
	if (top == nullptr)
	{
		cout << "\nStack is empty";
		return;
	}
	Node* temp = top;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Stack::peek()
{
	if (top == nullptr)
	{
		cout << "\nStack is empty";
		exit(1);
	}
	return top->data;
}

int main()
{
	Stack stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	
	stk.Display();
	cout << "Top element is: " << stk.peek() << endl;
	cout << "Popped element is: " << stk.pop() << endl;
	cout << "Popped element is: " << stk.pop() << endl;
	return 0;
}