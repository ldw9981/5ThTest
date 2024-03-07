#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int> linkedListInt;

	linkedListInt.PushBack(100);
	linkedListInt.PushBack(200);
	linkedListInt.PushBack(300);
	linkedListInt.Print();

	DoubleLinkedList<float> linkedListFloat;

	linkedListFloat.PushBack(100.1f);
	linkedListFloat.PushBack(200.1f);
	linkedListFloat.PushBack(300.1f);
	linkedListFloat.Print();

	return 0;
}