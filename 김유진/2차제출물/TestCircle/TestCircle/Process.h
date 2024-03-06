#pragma once
#include <Windows.h>
#include "LinkedList.h"

// 일단 시간이 없으니 구조가 이상해도 version.1을 만든다
class Circle
{
public:
	void Draw(HDC hdc)
	{
		Ellipse(hdc, x - r, y - r, x + r, y + r);
	}
	bool operator==(const Circle& other) const
	{
		if (x != other.x || y != other.y || r != other.r)
		{
			return false;
		}

		return true;
	}

	int x;
	int y;
	float r;
};

class Process
{
public:
	~Process()
	{
		ReleaseDC(hWnd, hdc);
		DeleteDC(backhdc);
		DeleteObject(bitmap);
	}

	void Init(HWND hwnd)
	{
		hWnd = hwnd;
		hdc = GetDC(hwnd);

		RECT rect;
		int width;
		int height;
		if (GetWindowRect(hWnd, &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}
		bitmap = CreateCompatibleBitmap(hdc, width, height);
		backhdc = CreateCompatibleDC(hdc);

		HBITMAP preBitmap = static_cast<HBITMAP>(SelectObject(backhdc, bitmap));
		DeleteObject(preBitmap);
	}

	void Update()
	{
		// 키 매니저를 만들면 좋겠지만...
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			Circle c;

			POINT mousePos;
			GetCursorPos(&mousePos);
			ScreenToClient(hWnd, &mousePos);

			c.x = mousePos.x;
			c.y = mousePos.y;
			c.r = 50;

			circleList.InsertBack(c);
		}
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			POINT mousePos;
			GetCursorPos(&mousePos);
			ScreenToClient(hWnd, &mousePos);

			for (int i = 0; i < circleList.GetSize(); i++)
			{
				Circle curCircle = circleList.Search(i);
				if(std::pow(curCircle.r, 2) >= (std::pow(curCircle.x - mousePos.x, 2) + std::pow(curCircle.y - mousePos.y, 2)))
				{
					int size = circleList.GetSize();
					//circleList.Delete(i); // delete를 하면 인덱스가 바뀐다
					removingList.InsertBack(curCircle);
				}
			}
			for (int i = 0; i < removingList.GetSize(); i++)
			{
				int size = removingList.GetSize();
				if (circleList.GetSize() > 0)
				{
					circleList.DeleteData(removingList.Search(i));
				}
				//Circle curCircle = removingList.Search(i);
			}
			int a = 3;
		}
	}

	void Render()
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
		RECT rc;
		GetClientRect(hWnd, &rc);
		FillRect(backhdc, &rc, hBrush);
		DeleteObject(hBrush);

		for (int i = 0; i < circleList.GetSize(); i++)
		{
			circleList.Search(i).Draw(backhdc);
		}

		RECT rect;
		int width;
		int height;
		if (GetWindowRect(hWnd, &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}

		BitBlt(hdc, 0, 0, width, height, backhdc, 0, 0, SRCCOPY);
	}

private:
	HWND hWnd;
	HDC hdc;
	HDC backhdc;
	HBITMAP bitmap;

	LinkedList<Circle> circleList;
	LinkedList<Circle> removingList;
};
