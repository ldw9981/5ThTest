#include "List.h"
#include <list>
#include <iostream>

using namespace std;

int main()
{
	List<int> test;
	test.PushFront(1);
	test.PushFront(2);
	test.PushFront(3);
	test.PushFront(4);
	test.eraser(test.Find(3));

	cout << test.Front() << " " << test.GetSize() << endl;
	test.PopFront();
	cout << test.Front() << " " << test.GetSize() << endl;
	test.PopFront();
	cout << test.Front() << " " << test.GetSize() << endl;
	test.PopFront();

	return 0;
}