#include "MyList.h"



int main()
{
	MyList<int> list;
	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushFront(3);

	list.Show();
	list.PopBack(); list.Show();
	list.PopFront(); list.Show();
	list.PopFront(); list.Show();
	list.PopBack(); list.Show();
	list.PopBack(); list.Show();

	list.PushBack(4);
	list.PushFront(5); list.Show();

	list.Clear(); list.Show();

	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	cout << list.Get(1) << endl;

	list.Erase(2); list.Show();

	return 0;
}
