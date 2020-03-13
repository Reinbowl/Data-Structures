#include "Tree.h"
#include <iostream>

using namespace std;

template <class T>
Tree<T>::Tree()
{
	size = 0;
	root = NULL;
}

template <class T>
void Tree<T>::insert(T data)
{
	Leaf<T>* new_leaf = new Leaf<T>(data);
	size++;
	if (root == NULL)
	{
		root = new_leaf;
		return;
	}
	Leaf<T>* pos = root;
	while (true)
	{
		if (data < pos->item)
		{
			if (pos->left != NULL)
			{
				pos = pos->left;
			}
			else
			{
				pos->left = new_leaf;
				return;
			}
		}
		else
		{
			if (pos->right != NULL)
			{
				pos = pos->right;
			}
			else
			{
				pos->right = new_leaf;
				return;
			}
		}
	}
}

template <class T>
void Tree<T>::remove(T data)
{
	if (root == NULL) //empty tree
	{
		cout << data << " is not in the tree." << endl;
		return;
	}

	Leaf<T>* pos = root;
	Leaf<T>* pos_parent = NULL,* suc_parent = NULL,* successor = NULL;
	if (root->item == data)
	{
		if (pos->right == NULL && pos->left == NULL) //no child
		{
			root = NULL;
		}
		else if (pos->right == NULL) //1 child
		{
			root = pos->left;
		}
		else if (pos->left == NULL) //1 child
		{
			root = pos->right;
		}
		else //2 child
		{
			successor = pos->right;
			if (successor->left == NULL)
			{
				successor->left = pos->left;
			}
			else
			{
				while (successor->left != NULL)
				{
					suc_parent = successor;
					successor = successor->left;
				}
				successor->left = pos->left;
				successor->right = pos->right;
				suc_parent->left = successor->right;
			}
			root = successor;
		}
		delete pos;
		size--;
		return;
	}

	while (pos->item != data) //finding item
	{
		pos_parent = pos;
		if (data < pos->item)
		{
			pos = pos->left;
		}
		else
		{
			pos = pos->right;
		}
		if (pos == NULL) //reach the end
		{
			cout << data << " is not in the tree." << endl;
			return;
		}
	}

	if (pos->right == NULL && pos->left == NULL) //no child
	{
		if (data < pos_parent->item)
		{
			pos_parent->left = NULL;
		}
		else
		{
			pos_parent->right = NULL;
		}
	}
	else if (pos->right == NULL) //1 child
	{
		if (data < pos_parent->item)
		{
			pos_parent->left = pos->left;
		}
		else
		{
			pos_parent->right = pos->left;
		}
	}
	else if (pos->left == NULL) //1 child
	{
		if (data < pos_parent->item)
		{
			pos_parent->left = pos->right;
		}
		else
		{
			pos_parent->right = pos->right;
		}
	}
	else //2 child
	{
		successor = pos->right;
		if (successor->left == NULL)
		{
			successor->left = pos->left;
		}
		else
		{
			while (successor->left != NULL)
			{
				suc_parent = successor;
				successor = successor->left;
			}
			suc_parent->left = successor->right;
			successor->left = pos->left;
			successor->right = pos->right;
		}
		if (data < pos_parent->item)
		{
			pos_parent->left = successor;
		}
		else
		{
			pos_parent->right = successor;
		}
	}
	delete pos;
	size--;
}

template <class T>
void Tree<T>::print()
{
	if(root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->item << " ";
	inOrder(root->right);
	cout << endl;
}

template <class T>
void Tree<T>::inOrder(Leaf<T>* parent)
{
	if (parent == NULL)
	{
		return;
	}
	inOrder(parent->left);
	cout << parent->item << " ";
	inOrder(parent->right);
}

template <class T>
void Tree<T>::find(T data)
{
	Leaf<T>* pos = root;
	while (pos->item != data) //finding item
	{
		if (data < pos->item)
		{
			pos = pos->left;
		}
		else
		{
			pos = pos->right;
		}
		if (pos == NULL) //reach the end
		{
			cout << data << " is not in the tree." << endl;
			return;
		}
	}
	cout << data << " is in the tree." << endl;
}