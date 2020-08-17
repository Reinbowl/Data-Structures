#pragma once
template <class T>
class Leaf
{
private:
	int rank;
	T item;
	Leaf<T>* parent;
	Leaf<T>* left;
	Leaf<T>* right;
public:
	Leaf(T);
	template <class T> friend class Tree;
};
#include "Leaf.hpp"