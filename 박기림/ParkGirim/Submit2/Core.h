#pragma once
#include "../LinkedList/LinkedList.h"

#include <Windows.h>

struct Circle 
{
	int left;
	int top;
	int right;
	int bottom;
};

class Core
{
public:
	void Run(HDC hdc);

	void CreateCircle(int x, int y, int radius);
	void DeleteCircle(int x, int y);

	LinkedList<Circle> circleList;
};

