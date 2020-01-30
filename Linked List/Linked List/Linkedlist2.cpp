#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void clear() //flushes the input buffer of cin
{
	cin.clear();
	cin.ignore(256, '\n');
}

int main()
{
	List* l = new List();
	string action;
	cout << "Type help to list commands." << endl;
	while (true)
	{
		cout << endl;
		cout << "Enter command: ";
		getline(cin, action);
		if (action.compare("insert") == 0)
		{
			int num;
			cout << "Enter number to insert: ";
			while (!(cin >> num))
			{
				cout << "Which part of number you don't understand? I mean I can knock some sense into you if you want." << endl;
				clear();
			}
			clear();
			cout << "Where do you want to insert the number? (head / index / tail) ";
			while (true)
			{
				getline(cin, action);
				if (action.compare("head") == 0)
				{
					l->push(num);
					break;
				}
				else if (action.compare("index") == 0)
				{
					int index;
					cout << "Enter which index to insert at (head is 1): ";
					while (!(cin >> index))
					{
						cout << "You know whats a number?" << endl;
						clear();
					}
					clear();
					l->insert(index, num);
					break;
				}
				else if (action.compare("tail") == 0)
				{
					l->append(num);
					break;
				}
				else
				{
					cout << "Enter a valid place to insert before I insert the number up you." << endl;
				}
			}
		}
		else if (action.compare("remove") == 0)
		{
			cout << "What do you want to remove? (head / index / number / tail) ";
			while (true)
			{
				getline(cin, action);
				if (action.compare("head") == 0)
				{
					l->remove(1);
					break;
				}
				else if (action.compare("index") == 0)
				{
					int index;
					cout << "Enter which index to remove (head is 1): ";
					while (!(cin >> index))
					{
						cout << "How hard is it to enter a number?" << endl;
						clear();
					}
					clear();
					l->remove(index);
					break;
				}
				else if (action.compare("tail") == 0)
				{
					l->removeTail();
					break;
				}
				else if (action.compare("number") == 0)
				{
					cout << "Haazah this shit aint implemented yet!" << endl;
					break;
				}
				else
				{
					cout << "Enter a valid thing to remove or I remove you from this Earth." << endl;
				}
			}

		}
		else if (action.compare("print") == 0)
		{
			l->print();
		}
		else if (action.compare("help") == 0)
		{
			cout << "Command list: insert, remove, print, exit" << endl;
		}
		else if (action.compare("exit") == 0)
		{
			break;
		}
		else
		{
			cout << "Type help and enter something valid before I invalid your existence." << endl;
		}
	}

	cout << "Deleting list..." << endl;
	delete l;
	cout << "Freeing memory so that it doesn't eat space like you." << endl;

	cout << endl;
	cout << "Bai Bai! <3" << endl;

	return 0;
}