#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> myLL;

	cout << "PushBack 1~5" << endl;
	for (int i = 1; i <= 5; i++)
	{
		myLL.PushBack(i);
		myLL.PrintAll();
	}

	cout << "PushFront 1~5" << endl;
	for (int i = 5; i >= 1; i--)
	{
		myLL.PushFront(i);
		myLL.PrintAll();
	}

	cout << "PopBack 2" << endl;
	myLL.PopBack();
	myLL.PrintAll();

	myLL.PopBack();
	myLL.PrintAll();

	cout << "PopFront 2" << endl;
	myLL.PopFront();
	myLL.PrintAll();

	myLL.PopFront();
	myLL.PrintAll();

	cout << "PopRemove 3" << endl;
	myLL.Remove(3);
	myLL.PrintAll();

	cout << "Clear" << endl;
	myLL.Clear();
	myLL.PrintAll();
}