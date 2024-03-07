#include "LinkedList.h"

int main()
{
	LinkedList<int> linkedList;
	linkedList.Push_Back(1);
	linkedList.Push_Back(1);
	linkedList.Push_Back(1);
	linkedList.Push_Back(1);
	linkedList.Push_Back(4);
	linkedList.Pop_Back();

	linkedList.Push_Back(4);
	linkedList.Erase(1);

	linkedList.Clear();

	linkedList.Push_Back(1);

	return 0;
}