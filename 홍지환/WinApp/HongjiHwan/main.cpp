#include <cassert>

#include <list>

#include "List.h"

int main(void)
{
	std::list<int> stdlist;
	stdlist.begin();

	// PushBack/PopBack/Back/End Iter
	{
		List<int> myList;

		myList.PushBack(10);
		assert(myList.GetCount() == 1);
		assert(myList.Back() == 10);
		assert(*(--myList.End()) == 10);

		myList.PushBack(20);
		assert(myList.GetCount() == 2);
		assert(myList.Back() == 20);
		assert(*(--myList.End()) == 20);

		myList.PushBack(30);
		assert(myList.GetCount() == 3);
		assert(myList.Back() == 30);
		assert(*(--myList.End()) == 30);

		myList.PopBack();
		assert(myList.GetCount() == 2);
		assert(myList.Back() == 20);
		assert(*(--myList.End()) == 20);

		myList.PopBack();
		assert(myList.GetCount() == 1);
		assert(myList.Back() == 10);
		assert(*(--myList.End()) == 10);

		myList.PopBack();
		assert(myList.GetCount() == 0);
	}

	// PushFront/PopFront/Front/Begin Iter
	{
		List<int> myList;

		myList.PushFront(10);
		assert(myList.GetCount() == 1);
		assert(myList.Front() == 10);
		assert(*(myList.Begin()) == 10);

		myList.PushFront(20);
		assert(myList.GetCount() == 2);
		assert(myList.Front() == 20);
		assert(*(myList.Begin()) == 20);

		myList.PushFront(30);
		assert(myList.GetCount() == 3);
		assert(myList.Front() == 30);
		assert(*(myList.Begin()) == 30);

		myList.PopFront();
		assert(myList.GetCount() == 2);
		assert(myList.Front() == 20);
		assert(*(myList.Begin()) == 20);

		myList.PopFront();
		assert(myList.GetCount() == 1);
		assert(myList.Front() == 10);
		assert(*(myList.Begin()) == 10);

		myList.PopFront();
		assert(myList.GetCount() == 0);
	}

	// insert, erase 1
	{
		List<int> myList;
		myList.PushBack(10);

		auto iter = myList.Begin();

		iter = myList.Insert(iter, 20);
		assert(*iter == 20);
		assert(iter == (--myList.End()));
		assert(myList.GetCount() == 2);

		iter = myList.Insert(iter, 30);
		assert(*iter == 30);
		assert(iter == (--myList.End()));
		assert(myList.GetCount() == 3);

		iter = myList.Erase(iter);
		assert(iter == myList.End());
		assert(myList.GetCount() == 2);
		--iter;

		iter = myList.Erase(iter);
		assert(iter == myList.End());
		assert(myList.GetCount() == 1);
		--iter;

		iter = myList.Erase(iter);
		assert(iter == myList.End());
		assert(myList.GetCount() == 0);
	}

	// insert, erase 2
	{
		List<int> myList;
		myList.PushBack(10);
		myList.PushBack(20);
		myList.PushBack(40);
		myList.PushBack(50);
		assert(myList.GetCount() == 4);

		auto iter = myList.Begin();
		myList.Insert(++iter, 30);
		assert(myList.GetCount() == 5);

		iter = myList.Begin();
		assert(*iter++ == 10);
		assert(*iter++ == 20);
		assert(*iter++ == 30);
		assert(*iter++ == 40);
		assert(*iter-- == 50);
		assert(*iter-- == 40);
		assert(*iter-- == 30);
		assert(*iter-- == 20);
		assert(*iter == 10);

		for (auto deleteIter = myList.Begin(); deleteIter != myList.End();)
		{
			deleteIter = myList.Erase(deleteIter);
		}

		assert(myList.GetCount() == 0);
	}

	// iter test;
	{
		List<int> myList;
		myList.PushBack(10);
		myList.PushBack(20);
		myList.PushBack(30);
		myList.PushBack(40);
		myList.PushBack(50);

		// myList.Begin()--; // == assert(false);
		// myList.End()++; // == assert(false);

		myList.Clear();
		assert(myList.GetCount() == 0);
	}

	// class Type
	{
		struct Circle
		{
			float CenterX;
			float CenterY;
			float Radius;
		};

		List<Circle> myList;

		myList.PushBack({ 10, 10, 10 });
		myList.PushBack({ 20, 20, 20 });
		myList.PushBack({ 30, 30, 30 });

		auto iter = myList.Begin();
		assert(iter->CenterX == 10);
		assert(iter->CenterY == 10);
		assert(iter->Radius == 10);
		iter->CenterX = 110;
		assert(iter->CenterX == 110);
		(*iter).CenterX = 10;
		assert(iter->CenterX == 10);
		++iter;

		assert(iter->CenterX == 20);
		assert(iter->CenterY == 20);
		assert(iter->Radius == 20);
		iter->CenterX = 110;
		assert(iter->CenterX == 110);
		(*iter).CenterX = 20;
		assert(iter->CenterX == 20);
		++iter;

		assert(iter->CenterX == 30);
		assert(iter->CenterY == 30);
		assert(iter->Radius == 30);
		iter->CenterX = 110;
		assert(iter->CenterX == 110);
		(*iter).CenterX = 30;
		assert(iter->CenterX == 30);
		++iter;
	}
}