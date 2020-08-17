#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

class node
{
private:
	int item;
	node* next;
public:
	node(int n) { item = n; next = NULL; };
	friend class stack;
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

bool _DFS(vector<vector<int>> g, int v[], int i, int x)
{
	if (v[i] == 1)
	{
		return false;
	}
	v[i] = 1;
	stack s;
	int j;
	for (j = 0; g[i][j] != -1; j++)
	{
		if (g[i][j] == x)
		{
			cout << x << " ";
			return true;
		}
		s.push(g[i][j]);
	}
	while (j > 0)
	{
		int a = s.pop();
		if (_DFS(g, v, a, x))
		{
			cout << a << " ";
			return true;
		}
		j--;
	}
}

void DFS(vector<vector<int>> graph, int x)
{
	int v[5] = { 0 };
	int s = 1;
	if(_DFS(graph, v, s, x))
		cout << s << endl;
}

int main()
{
	vector<vector<int>> graph;
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(-1);
	graph.push_back(v);
	v.clear();
	v.push_back(2);
	v.push_back(4);
	v.push_back(-1);
	graph.push_back(v);
	v.clear();
	v.push_back(1);
	v.push_back(-1);
	graph.push_back(v);
	v.clear();
	v.push_back(0);
	v.push_back(-1);
	graph.push_back(v);
	v.clear();
	v.push_back(0);
	v.push_back(1);
	v.push_back(-1);
	graph.push_back(v);

	DFS(graph, 3);

	return 0;
}