#pragma once
#include "Leaf.h"
template <class T>
class Tree
{
private:
	int size;
	Leaf<T>* root;
	void inOrder(Leaf<T>*);
public:
	Tree();
	void insert(T);
	void remove(T);
	void print();
	void find(T);
};
#include "Tree.hpp"

