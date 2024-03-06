#include <iostream>
#include "LinkedList.h"

int main()
{

	List<int> list;
	Node<int>* a = new Node<int>;
	Node<int>* b = new Node<int>;
	Node<int>* c = new Node<int>;
	Node<int>* d = new Node<int>;

	a->data = 1;
	b->data = 0;
	c->data = 3;
	d->data = 4;

	list.Add(a);
	list.Add(b);
	list.Add(c);
	list.Insert(2,d);
	std::cout << list.GetNode(2)->data << std::endl;
	list.Delete(2);
	std::cout << list.GetNode(2)->data << std::endl;


	std::cout << "size : " << list.Size() << std::endl;

	return 0;
}