#include "Hashtable.h"
using namespace std;

template <class T>
Hashtable<T>::Hashtable(int s)
{
	size = s;
	Table = new HashNode<T> *[size]();
}

template <class T>
int Hashtable<T>::Hashfunc(int key)
{
	return key % size;
}

template <class T>
void Hashtable<T>::insert(int key, T item)
{
	int index = Hashfunc(key);
	HashNode<T>* pos = Table[index];
	if (pos == NULL)
	{
		Table[index] = new HashNode<T>(key, item);
		return;
	}
	while (pos->next != NULL)
	{
		pos = pos->next;
	}
	pos->next = new HashNode<T>(key, item);
}

template <class T>
T Hashtable<T>::search(int key)
{
	int index = Hashfunc(key);
	HashNode<T>* pos = Table[index];
	while (pos->key != key)
	{
		if (pos == NULL)
		{
			return T();
		}
		pos = pos->next;
	}
	return pos->item;
}