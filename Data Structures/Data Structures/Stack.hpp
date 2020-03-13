#include "Stack.h"
#include <iostream>

template <class T>
Stack<T>::Stack()
{
	size = 0;
	next = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (size > 0)
	{
		pop();
	}
}

template <class T>
void Stack<T>::print()
{
	if (size > 0)
	{
		Node<T>* n = next;
		for (int i = 0; i < size; i++)
		{
			std::cout << n->data << " ";
			n = n->next;
		}
		std::cout << std::endl;
	}
}

template <class T>
void Stack<T>::push(T n)
{
	Node<T>* new_node = new Node<T>(n);
	size++;
	new_node->next = next;
	next = new_node;
}

template <class T>
void Stack<T>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = next;
		next = temp->next;
		size--;
	}
}

template <class T>
T Stack<T>::peek()
{
	return size > 0 ? next->data : -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (size == 0);
}

template<class T>
inline void Stack<T>::reverse()
{
	Node<T>* pos = next, * prvs = NULL, * temp;
	while (pos)
	{
		temp = pos->next;
		pos->next = prvs;
		prvs = pos;
		pos = temp;
	}
	next = prvs;
}
