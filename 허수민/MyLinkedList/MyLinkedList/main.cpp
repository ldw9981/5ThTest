#include <string>
#include "MyLinkedList.h"

void TestMyStringDataLinkedList();
void TestMyIntegerDataLinkedList();

int main()
{
	TestMyIntegerDataLinkedList();
	TestMyStringDataLinkedList();

	return 0;
}

void TestMyStringDataLinkedList()
{
	MyLinkedList<std::string> test;

	test.Add("A");

	test.PrintAll();
	test.DeleteByData("A");

	test.Add("B");
	test.Add("C");
	test.Add("D");

	test.PrintAll();
	test.DeleteAll();
	test.PrintAll();

	test.Add("E");
	test.Add("F");
	test.Add("G");
	test.Add("H");

	test.PrintAll();
	test.DeleteByData("F");
	test.PrintAll();

	test.Add("I");
	test.Add("J");

	test.PrintAll();
	test.DeleteByData("F");
	test.PrintAll();
}

void TestMyIntegerDataLinkedList()
{
	MyLinkedList<int> test;

	test.Add(10);

	test.PrintAll();
	test.DeleteByData(10);

	test.Add(20);
	test.Add(30);
	test.Add(40);

	test.PrintAll();
	test.DeleteAll();
	test.PrintAll();

	test.Add(50);
	test.Add(60);
	test.Add(70);
	test.Add(80);

	test.PrintAll();
	test.DeleteByData(60);
	test.PrintAll();

	test.Add(90);
	test.Add(100);

	test.PrintAll();
	test.DeleteByData(60);
	test.PrintAll();
}
