#pragma once
#include <iostream>
#include "Node.h"
template <class T>
class HashNode
{
private:
	T item;
	int key;
	HashNode* next;
public:
	HashNode(int, T);
	template <class T> friend class Hashtable;
};
#include "HashNode.hpp"