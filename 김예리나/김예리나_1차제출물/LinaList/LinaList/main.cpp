#include "LinaList.h"

int main()
{
	LinaList<int> list;

	list.pushBack(11);
	list.pushBack(22);
	list.pushBack(33);
	list.pushBack(44);
	list.Print();
	cout << "---" << endl;

	auto lina = list.Begin();
	++lina;
	++lina;
	list.Insert(lina,777);

	list.Print();
	cout << "---" << endl;

	auto lina2 = list.Begin();
	++lina2;
	++lina2;
	list.Erase(lina2);
	list.Print();
	cout << "---" << endl;
	

	while (true)
	{

	}

	return 0;
}