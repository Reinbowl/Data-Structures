// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

void display(Node* n)
{
	cout << "Current list is ";
	while (n->next != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << n->data << endl;
}

void addFront(Node** headptr, int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = *headptr; //next node is the prvs head
	*headptr = new_node; //change head to point to new node
}

void addBack(Node** headptr, int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;

	if (*headptr == NULL)
	{
		*headptr = new_node;
	}

	Node* last = *headptr;

	while (last->next != NULL)
	{
		last = last->next;
	}
	
	last->next = new_node;
}

void insertAfter(Node** n, int data)
{
	if (*n == NULL)
	{
		cout << "Node cant be NULL" << endl;
		return;
	}

	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = (*n)->next; //new node to point to next
	(*n)->next = new_node; //node to point to new node
}

int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	addFront(&head, 4);
	insertAfter(&second, 8);
	addBack(&head, 5);

	display(head);
}
