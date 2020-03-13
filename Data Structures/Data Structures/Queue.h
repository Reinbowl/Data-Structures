#pragma once
#include "Node.h"
template <class T>
class Queue //FIFO
{
private:
	int size;
	Node<T>* start;
public:
	Queue();
	~Queue();
	void enqueue(T);
	void dequeue();
	T peek();
	void print();
};
#include "Queue.hpp"

