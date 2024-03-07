#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> list;

	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(3);

	list.Display(list.getHead());

	list.AddFrontNode(5);
	list.Delete(list.getHead()->nextNode);

	list.Display(list.getHead());

	list.Insert(list.getHead()->nextNode->nextNode, 7);

	list.Display(list.getHead());
}