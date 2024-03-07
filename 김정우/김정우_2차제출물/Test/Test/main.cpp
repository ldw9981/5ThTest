#include "LinkedList.h"

int main()
{
	LinkedList<int> intList;
	cout << "push back\n";
	intList.PushBack(100);
	intList.PushBack(200);
	intList.PushBack(300);
	intList.PushBack(400);
	intList.Print();

	cout << "insert after\n";
	ListIterator<int> iter = intList.Begin();
	++iter;
	intList.InsertAfter(iter, 500);
	intList.Print();

	cout << "erase after\n";
	++iter;
	intList.EraseAfter(iter);
	intList.Print();

	cout << "pop front\n";
	intList.PopFront();
	intList.Print();

	cout << "push front\n";
	intList.PushFront(600);
	intList.Print();

	cout << "clear\n";
	intList.Clear();
	intList.Print();

	return 0;
}