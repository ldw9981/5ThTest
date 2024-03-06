#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	list.Push_back(1);
	list.Push_back(2);
	list.Push_back(3);
	list.Push_back(4);
	list.Push_back(5);
	list.Push_back(6);
	list.Push_back(7);


	list.Push(3, 33);

	list.Pop(3);
	

	list.Pop_back();
	list.Pop_back();

	LinkedList<int> copy(list);
	copy.Push_back(6);

	LinkedList<int> copy2 = list;
	copy2.Push_back(7);

}