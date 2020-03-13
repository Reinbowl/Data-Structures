#include "Leaf.h"
#include <iostream>

template <class T>
Leaf<T>::Leaf(T data)
{
	item = data;
	left = NULL;
	right = NULL;
}