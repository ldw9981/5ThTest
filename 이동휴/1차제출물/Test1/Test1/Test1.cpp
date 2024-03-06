#include <iostream>
#include "Mylist.h"
using namespace std;
int main()
{
	Mylist<int> testlist;
	for (size_t i = 0; i < 10; i++)
	{
		testlist.push_back(i);
	}
	for (size_t i = 0; i < 10; i++)
	{
		testlist.push_front(i);
	}
	for (auto i= testlist.begin(); i!=testlist.end(); ++i)
	{
		std::cout << *i;
	}
	cout << "\n";
	for (auto i = testlist.begin(); i != testlist.end(); ++i)
	{
		if (*i ==4||*i == 6)
		{
			auto temp = testlist.erase(i);
			i= temp;
		}
		cout << *i;
	}
}
