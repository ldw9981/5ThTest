#include "LinkedList.h"

int main()
{
	LinkedList<int> linkedList;
	linkedList.Insert(3);
	linkedList.PrintAll();
	linkedList.Insert(4);
	linkedList.PrintAll();
	linkedList.Insert(5);
	linkedList.PrintAll();
	linkedList.Insert(6);
	linkedList.Delete(linkedList.GetNode(0));
	linkedList.PrintAll();
	linkedList.Delete(linkedList.Find(5));
	linkedList.PrintAll();
	linkedList.DeleteBack();
	linkedList.DeleteBack();
	linkedList.DeleteBack();
	linkedList.DeleteBack();
	linkedList.PrintAll();

	LinkedList<const char*> linkedListC;
	linkedListC.Insert("H");
	linkedListC.PrintAll();
	linkedListC.Insert("E");
	linkedListC.PrintAll();
	linkedListC.Insert("L");
	linkedListC.PrintAll();
	linkedListC.Insert("L");
	linkedListC.PrintAll();
	linkedListC.Insert("O");
	linkedListC.Delete(linkedListC.GetNode(2));
	linkedListC.PrintAll();
	linkedListC.Delete(linkedListC.Find("L"));
	linkedListC.PrintAll();
	linkedListC.DeleteBack();
	linkedListC.DeleteBack();
	linkedListC.DeleteBack();
	linkedListC.DeleteBack();
	linkedListC.PrintAll();
}