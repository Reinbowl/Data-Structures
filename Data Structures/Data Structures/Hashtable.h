#pragma once
#include <iostream>
#include "HashNode.h"
template <class T>
class Hashtable
{
private:
	int Hashfunc(int); //hash key and return position in table
	HashNode<T>** Table;
	int size;
public:
	Hashtable(int);
	void insert(int, T); //insert item with key
	T search(int); //finds item at key
};
#include "Hashtable.hpp"