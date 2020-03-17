#include "HashNode.h"
template <class T>
HashNode<T>::HashNode(int k, T x)
{
	item = x;
	key = k;
	next = NULL;
}