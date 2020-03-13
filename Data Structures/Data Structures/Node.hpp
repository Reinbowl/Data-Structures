#include "Node.h"
#include <iostream>

template <class T>
Node<T>::Node(T n)
{
	data = n;
	next = NULL;
}