#pragma once
template <class T>
class Leaf
{
private:
	T item;
	Leaf<T>* left;
	Leaf<T>* right;
public:
	Leaf(T);
	template <class T> friend class Tree;
};
#include "Leaf.hpp"