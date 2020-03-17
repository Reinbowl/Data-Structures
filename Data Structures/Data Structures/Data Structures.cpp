#include <iostream>
#include "Stack.h"
#include "Tree.h"
#include "Queue.h"
#include "Hashtable.h"

using namespace std;

int main()
{
    Hashtable<int>* t = new Hashtable<int>(5);
    t->insert(3, 50);
    t->insert(4, 40);
    t->insert(5, 13);
    t->insert(8, 20);
    cout << t->search(8) << " " << t->search(3) << endl;

    return 0;
}