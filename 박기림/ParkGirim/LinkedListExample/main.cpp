#include <iostream>
#include "../LinkedList/LinkedList.h"

int main()
{
	// int type LinkedList
	LinkedList<int> myLinkedList;

	// test : InsertFront, InsertBack
	myLinkedList.InsertBack(1);
	myLinkedList.InsertBack(2);
	myLinkedList.InsertBack(3);
	myLinkedList.InsertBack(4);
	myLinkedList.InsertBack(5);
	myLinkedList.InsertBack(6);
	myLinkedList.InsertFront(7);
	myLinkedList.InsertFront(8);
	myLinkedList.PrintAll();

	// test : 중간에 있는 노드 Delete
	myLinkedList.DeleteNode(4);
	myLinkedList.PrintAll();

	// string type LinkedList
	LinkedList<std::string> stringLinkedList;

	// test : InsertFont, InsertBack
	stringLinkedList.InsertFront("apple");
	stringLinkedList.InsertBack("banana");
	stringLinkedList.InsertBack("cat");
	stringLinkedList.InsertFront("dog");
	stringLinkedList.PrintAll();

	// test : head, tail Node Delete
	stringLinkedList.DeleteNode("cat");
	stringLinkedList.PrintAll();
	stringLinkedList.DeleteNode("dog");
	stringLinkedList.PrintAll();

	return 0;
}