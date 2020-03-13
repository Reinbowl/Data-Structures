#include <iostream>
#include "Stack.h"
#include "Tree.h"
#include "Queue.h"

using namespace std;

int main()
{
    Queue<char>* q = new Queue<char>();
    q->enqueue('a');
    q->enqueue('d');
    q->enqueue('g');
    q->dequeue();
    q->print();

    return 0;
}