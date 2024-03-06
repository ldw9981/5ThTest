#include "List.h"

int main()
{
	std::cout << "front/insert test" << std::endl;

	List<int> list = List<int>(10);
	list.push_front(30);
	list.push_front(20);
	list.push_front(30);
	list.push_front(40);
	list.push_front(50);
	list.insert(7, 99);

	int num = list.size();
	for (int i = 0; i < num; i++)
	{
		std::cout << list.pop_front() << ' ';
	}

	std::cout << "\nback/insert test" << std::endl;

	list.push_back(30);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);
	list.push_back(50);
	list.insert(0, 99);

	num = list.size();
	for (int i = 0; i < num; i++)
	{
		std::cout << list.pop_front() << ' ';
	}

	std::cout << "\nremove test" << std::endl;

	list.push_back(20);
	list.push_back(50);
	list.push_back(20);
	list.push_back(20);
	list.push_back(20);
	list.push_back(20);
	list.push_back(50);
	list.push_back(20);

	list.remove(20);

	num = list.size();
	for (int i = 0; i < num; i++)
	{
		std::cout << list.pop_front() << ' ';
	}

}