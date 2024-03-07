#pragma once
#include "resource.h"

#include "../List/List.h"

static int g_width = 0;
static int g_height = 0;

struct MyCircle
{
	int _x;
	int _y;
	int _rad;

	MyCircle(int x, int y, int rad) : _x(x), _y(y), _rad(rad) {}
};

class CircleManager
{
private:
	CircleManager() = default;

public:
	static CircleManager& Inst()
	{
		static CircleManager inst;
		return inst;
	}

	void Init(HWND hWnd)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);
	}

	void Render()
	{
		for (auto it = _circleList.begin(); it != _circleList.end(); it++)
		{
			Ellipse(_hdc, 
				it->_x - it->_rad, 
				it->_y - it->_rad, 
				it->_x + it->_rad, 
				it->_y + it->_rad);
		}
	}

	void Draw(int x, int y)
	{
		_circleList.emplace_back(x, y, 50);
	}

	void Remove(int x, int y)
	{
		auto it = _circleList.begin();

		while (it != _circleList.end())
		{
			if (!(it->_x - it->_rad <= x and x <= it->_x + it->_rad) or !(it->_y - it->_rad <= y and y <= it->_y + it->_rad))
			{
				it++;
				continue;
			}
			
			InvalidateRect(_hWnd, nullptr, 1);
			it = _circleList.erase(it);
		}
	}

private:
	HWND _hWnd = nullptr;
	HDC _hdc = nullptr;
	List<MyCircle> _circleList;
};
