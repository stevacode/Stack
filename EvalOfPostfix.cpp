#include "Stack.h"
#include <stdlib.h>
#include <cstring>
using namespace std;

struct Node
{
	int data;
	Node* next;
}*top = NULL;

void push(int x)
{
	Node* t = new Node;
	if (t == NULL)
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	int x = -1;
	if (top == NULL)
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		Node* t = top;
		top = top->next;
		x = t->data;
		delete t;
	}
	return x;
}

void Display()
{
	Node* p = top;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int isBalanced(char* exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			if (top == NULL)
			{
				return 0;
			}
			pop();
		}
	}
	return top == NULL ? 1 : 0;
}

int pre(char x)
{
	if (x == '+' || x == '-')
	{
		return 1;
	}
	else if (x == '*' || x == '/')
	{
		return 2;
	}
	return 0;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
	{
		return 0;
	}
	return 1;
}

char* InfixToPostfix(char* infix)
{
	int len = strlen(infix);
	char* postfix = new char[len + 1];
	int i = 0, j = 0;
	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if (pre(infix[i]) > pre(top->data))
			{
				push(infix[i++]);
			}
			else
			{
				postfix[j++] = pop();
			}
		}
	}
	while (top != NULL)
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	return postfix;
}

int evaluatePostfix(char* postfix)
{
	int i = 0;
	while (postfix[i] != '\0')
	{
		if (isOperand(postfix[i]))
		{
			push(postfix[i] - '0');
		}
		else
		{
			int op2 = pop();
			int op1 = pop();
			switch (postfix[i])
			{
			case '+':
				push(op1 + op2);
				break;
			case '-':
				push(op1 - op2);
				break;
			case '*':
				push(op1 * op2);
				break;
			case '/':
				push(op1 / op2);
				break;
			}
		}
		i++;
	}
	return pop();
}

int main()
{
	char* postfix = "234*+82/-";
	cout << "Postfix: " << postfix << endl;
	cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
	cout << endl;


	return 0;
}