#pragma once
template <class T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node(T);
	template <class T> friend class Stack;
	template <class T> friend class Queue;
};
#include "Node.hpp"