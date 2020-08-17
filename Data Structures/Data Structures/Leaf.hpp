#include "Leaf.h"
#include <iostream>

template <class T>
Leaf<T>::Leaf(T data)
{
	rank = 0;
	item = data;
	parent = NULL;
	left = NULL;
	right = NULL;
}