#include <list>
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	cout << "<<<<< LIST >>>>>" << endl;
	list<int> li1;
	li1.push_back(1);
	li1.push_back(2);
	li1.push_back(3);
	cout << "ORIGIN" << endl;
	for (list<int>::iterator a = li1.begin(); a != li1.end(); a++)
	{
		cout << *a << endl;
	}
	list<int>::iterator c = li1.begin();
	c++;
	auto b = li1.insert(c, 8);
	cout << "INSERT" << endl;
	for (list<int>::iterator a = li1.begin(); a != li1.end(); a++)
	{
		cout << *a << endl;
	}
	cout << "iterator : " << * b << endl;
	
	// DELETE
	cout << "DELETE" << endl;
	b = li1.erase(b);
	for (list<int>::iterator a = li1.begin(); a != li1.end(); a++)
	{
		cout << *a << endl;
	}
	cout << "iterator : " << * b << endl;

	cout << "list" << endl;


	cout << "<<<<< LINKED LIST >>>>>" << endl;


	LinkedList<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	cout << "ORIGIN" << endl;
	for (LinkedList<int>::Iterator a = li.begin(); a != li.end(); a++)
	{
		cout << *a << endl;
	}

	cout << "INSERT" << endl;
	LinkedList<int>::Iterator a = li.begin();
	a++;
	LinkedList<int>::Iterator d = li.insert(a, 8);

	for (LinkedList<int>::Iterator a = li.begin(); a != li.end(); a++)
	{
		cout << *a << endl;
	}
	cout << *d << endl;

	// DELETE
	cout << "DELETE" << endl;
	d = li.erase(d);
	for (LinkedList<int>::Iterator a = li.begin(); a != li.end(); a++)
	{
		cout << *a << endl;
	}
	cout << "iterator : " << * d << endl;

	cout << "ALL DELETE" << endl;
	while (li.size())
	{
		li.pop_back();
	}
	for (LinkedList<int>::Iterator a = li.begin(); a != li.end(); a++)
	{
		cout << *a << endl;
	}

	cout << "LinkedList" << endl;
}