class Node
{
private:
	int data;
	Node* next;
public:
	Node(int);
friend class List;
};