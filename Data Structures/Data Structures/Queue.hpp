#include "Queue.h"
#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue()
{
	size = 0;
	start = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	while (size > 0)
	{
		dequeue();
	}
}

template <class T>
void Queue<T>::enqueue(T data)
{
	Node<T>* new_node = new Node<T>(data);
	if (start == NULL)
	{
		start = new_node;
		return;
	}
	Node<T>* pos = start;
	while (pos->next)
	{
		pos = pos->next;
	}
	pos->next = new_node;
}

template <class T>
void Queue<T>::dequeue()
{
	if (!start)
	{
		cout << "Queue already empty." << endl;
		return;
	}
	Node<T>* pos = start;
	start = pos->next;
	delete pos;
}

template <class T>
void Queue<T>::print()
{
	Node<T>* pos = start;
	while (pos)
	{
		cout << pos->data << " ";
		pos = pos->next;
	}
	cout << endl;
}

template <class T>
T Queue<T>::peek()
{
	return start->data;
}