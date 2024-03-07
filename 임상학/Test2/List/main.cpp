#include "List.h"

class MyClass
{
public:
	MyClass(int a, int b) : _a(a), _b(b) {}

	int _a;
	int _b;
};

int main()
{
	List<MyClass> myList;

	myList.push_back(MyClass{ 3, 4 });
	myList.push_back(MyClass{ 5, 6 });
	myList.push_back(MyClass{ 7, 8 });		
	myList.emplace_back(9, 10);

	myList.insert(myList.begin(), 2, MyClass{ 1, 2 });
	myList.erase(myList.begin());

	return 0;
}