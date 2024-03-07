#include <iostream>
#include "List.h"

int main()
{
	Changdo::List<int> myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_back(5);

	auto iter = myList.begin();
	auto iter2 = myList.end();
	++iter;
	--iter2;

	auto iter3 = myList.Insert(myList.end(), 10, 10);

	auto iter4 = myList.emplace(iter3, 11);

	//auto ret = myList.erase(iter);

	//auto ret = myList.erase(iter, iter2);

	auto findedIter = myList.find_if(
		myList.begin(), myList.end(),
		[](int a)->bool
		{
			return a == 2;
		}
	);

	myList.clear();
	myList.clear();


	int a = 0;
	return 0;
}