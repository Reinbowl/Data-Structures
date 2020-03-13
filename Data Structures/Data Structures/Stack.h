#pragma once
#include "Node.h"
template <class T>
class Stack //LIFO
{
private:
	int size;
	Node<T>* next;
public:
	Stack();
	~Stack();
	void print();
	void push(T);
	void pop();
	T peek();
	bool isEmpty();
	void reverse();
};
#include "Stack.hpp"