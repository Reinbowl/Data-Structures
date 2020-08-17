#include <iostream>

class node
{
private:
	int item;
	node* next;
public:
	node(int n) { item = n; next = NULL; };
	friend class stack;
	friend class queue;
	friend class pqueue;
};

class stack
{
private:
	node* head;
public:
	stack() { head = NULL; };
	void push(int);
	int pop();
	void clear() { head = NULL; };
};

void stack::push(int n)
{
	node* new_node = new node(n);
	new_node->next = head;
	head = new_node;
	node* x = head;
}

int stack::pop()
{
	if (head == NULL)
	{
		return -1;
	}
	node* temp = head;
	head = head->next;
	int pop_item = temp->item;
	delete temp;
	return pop_item;
}

class queue
{
private:
	node* head;
public:
	queue() { head = NULL; };
	void enqueue(int);
	int dequeue();
	void clear() { head = NULL; };
};

void queue::enqueue(int n)
{
	if (head == NULL)
	{
		head = new node(n);
	}
	else
	{
		node* pos = head;
		while (pos->next != NULL)
		{
			pos = pos->next;
		}
		pos->next = new node(n);
	}
}

int queue::dequeue()
{
	if (head == NULL)
	{
		return -1;
	}
	node* temp = head;
	head = head->next;
	int pop_item = temp->item;
	delete temp;
	return pop_item;
}

class pqueue
{
private:
	node* head;
public:
	pqueue() { head = NULL; };
	void enqueue(int);
	int dequeue();
	void clear() { head = NULL; };
};

void pqueue::enqueue(int n)
{
	if (head == NULL)
	{
		head = new node(n);
	}
	else
	{
		node* new_node = new node(n);
		if (n > head->item)
		{
			new_node->next = head;
			head = new_node;
		}
		else
		{
			node* pos = head;
			while (pos->next != NULL && pos->item > n)
			{
				pos = pos->next;
			}
			new_node->next = pos->next;
			pos->next = new_node;
		}
	}
}

int pqueue::dequeue()
{
	if (head == NULL)
	{
		return -1;
	}
	node* temp = head;
	head = head->next;
	int pop_item = temp->item;
	delete temp;
	return pop_item;
}


int main()
{
	stack s;
	queue q;
	pqueue pq;
	int num_command, command, n, i;
	bool type[3];

	while (std::cin >> num_command)
	{
		s.clear(); q.clear(); pq.clear();
		type[0] = true; type[1] = true; type[2] = true;
		for (i = 0; i < num_command; i++)
		{
			std::cin >> command;
			switch (command)
			{
			case 1: std::cin >> n;
				s.push(n);
				q.enqueue(n);
				pq.enqueue(n);
				break;
			case 2:	std::cin >> n;
				type[0] = (s.pop() == n && type[0]);
				type[1] = (q.dequeue() == n && type[1]);
				type[2] = (pq.dequeue() == n && type[2]);
				break;
			}
		}
		if (type[0] && !type[1] && !type[2])
		{
			std::cout << "stack" << std::endl;
		}
		else if (!type[0] && type[1] && !type[2])
		{
			std::cout << "queue" << std::endl;
		}
		else if (!type[0] && !type[1] && type[2])
		{
			std::cout << "priority queue" << std::endl;
		}
		else if (!type[0] && !type[1] && !type[2])
		{
			std::cout << "impossible" << std::endl;
		}
		else
		{
			std::cout << "not sure" << std::endl;
		}
	}
}