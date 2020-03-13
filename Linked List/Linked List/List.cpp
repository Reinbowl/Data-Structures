#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
	size = 0;
	next = NULL;
}

List::~List()
{
	while (size > 0)
	{
		remove(1);
	}
}

void List::print()
{
	cout << "List size: " << size << endl;
	if (size == 0)
	{
		cout << "List is empty. Like your life." << endl;
		return;
	}
	else
	{
		cout << "Data in list: ";
		Node* node = next;
		while (node->next != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << node->data << endl;
	}
}

void List::push(int n)
{
	Node* new_node = new Node(n);
	size++;
	new_node->next = next;
	next = new_node;
}

void List::append(int n)
{
	if (size == 0)
	{
		push(n);
		return;
	}

	Node* new_node = new Node(n);
	size++;
	Node* last = next;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
}

void List::insert(int index, int n)
{
	if (index > size || index < 1) //invalid index
	{
		cout << "Invalid index." << endl;
		return;
	}

	if (index == 1 || size == 0)
	{
		push(n);
		return;
	}

	Node* new_node = new Node(n);
	size++;
	Node* pos = next;
	for (int i = 1; i < index - 1; i++)
	{
		pos = pos->next;
	}
	new_node->next = pos->next;
	pos->next = new_node;
}

void List::remove(int index)
{
	if (size == 0)
	{
		cout << "There's nothing to remove, don't make me remove you." << endl;
		return;
	}
	if (index > size || index < 1) //invalid index
	{
		cout << "Invalid index." << endl;
		return;
	}

	Node* temp = next;
	if (index == 1) //remove first node
	{
		next = next->next;
		delete temp;
		size--;
		return;
	}

	Node* node = temp;
	if (index == size) //remove last node
	{
		for (int i = 1; i < size; i++)
		{
			node = temp;
			temp = temp->next;
		}
		node->next = NULL;
		delete temp;
		size--;
		return;
	}

	for (int i = 1; i < index; i++)
	{
		node = temp;
		temp = temp->next;
	}
	node->next = temp->next;
	delete temp;
	size--;
}

void List::removeTail()
{
	remove(size);
}