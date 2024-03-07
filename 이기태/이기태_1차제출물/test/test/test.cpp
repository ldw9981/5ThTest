
#include <iostream>
#include "list.h"

int main()
{
	my::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	// print
	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';
	
	// 한개 삭제
	{
		auto iter = l.begin();
		l.erase(iter);
	}

	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';

	// 모두 삭제
	for (int i = 0; i < 4; ++i)
	{
		auto iter = l.begin();
		l.erase(iter);
	}

	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';

	for (int i = 0; i < 100; ++i)
	{
		l.push_back(i);
	}

	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';

	// 3의 배수 삭제
	for (auto iter = l.begin(); iter != l.end(); )
	{
		if (*iter % 3 == 0)
		{
			iter = l.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';

	l.clear();
	for (int& i : l)
	{
		std::cout << i << ' ';
	}
	std::cout << "size : " << l.get_size() << '\n';

}

