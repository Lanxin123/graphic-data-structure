#include "stdafx.h"
#include <iostream>
using namespace std;

template <class Type>
struct Node
{
	Type data;
	Node *next;
};

template<class Type>
class Linkedlist
{
private:
	Node<Type>* top;
	Node<Type>* deptr;
public:
	Linkedlist()
	{
		top = NULL;
	}
	void push(Type data);
	Type pop();
};
template<class Type>
void Linkedlist<Type>::push(Type data)
{
	Node<Type>* newNode=  new Node<Type>;
	newNode->data = data;
	newNode->next = top;
	top = newNode;
}

template<class Type>
Type Linkedlist<Type>::pop()
{
	int p_data;
	if (top ==NULL)
	{
		cout << "栈为空" << endl;
		return 0;
	}
	p_data = top->data;
	deptr = top;
	top = top->next;
	delete deptr;
	return p_data;
}

int main()
{
	int i_data;
	Linkedlist<int> stack_1;
	cin >> i_data;
	stack_1.push(i_data);
	cout << stack_1.pop() << endl;
	char c_data;
	Linkedlist<char> stack_2;
	cin >> c_data;
	stack_2.push(c_data);
	cout << stack_2.pop() << endl;
}





