#include "linked_list.h"

void main()
{
	cout << "[char]" << endl;
	LinkedList<char> list1;
	list1.PrintAll();
	list1.PushBack('a');
	list1.PushBack('b');
	list1.PushBack('c');
	list1.PushBack('d');
	list1.PrintAll();
	list1.PopBack();
	list1.PopBack();
	list1.PrintAll();
	list1.PushFront('e');
	list1.PushFront('f');
	list1.PushFront('g');
	list1.PrintAll();
	list1.PopFront();
	list1.PopFront();
	list1.PrintAll();
}