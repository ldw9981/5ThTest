#include <iostream>
#include "LinkedList.h"


void main()
{
	LinkedList<int> list;

	list.PushBack(0);
	list.PushBack(5);
	list.PushBack(6);
	list.PushBack(2);
	list.PushBack(5);
	list.PushBack(3);
	list.PushBack(8);
	list.PushBack(1);

	list.Insert(3, 4);

	for (size_t i = 0; i < 100; i++)
	{
		int data;
		if (list.GetData(i, data) == false)
			break;
		printf("%d ", data);
	}
	printf("\n");
	list.DeleteAll();
	for (size_t i = 0; i < 100; i++)
	{
		int data;
		if (list.GetData(i, data) == false)
			break;
		printf("%d ", data);
	}
	printf("\n");

}