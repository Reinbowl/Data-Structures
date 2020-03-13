#pragma once
#include "Node.h"

class List
{
private:
	int size;
	Node* next;
public:
	List();
	~List();
	void print();
	void push(int); //add new node to head
	void append(int); //add new node to tail
	void insert(int, int); //insert node at index
	void remove(int); //remove node at index
	void removeTail();
};