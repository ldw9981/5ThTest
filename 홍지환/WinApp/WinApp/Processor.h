#pragma once

#include <Windows.h>
#include <cmath>

#include "../HongjiHwan/List.h"
#include "Circle.h"

class Processor
{
public:
	void Init(HWND hwnd)
	{
		mHWnd = hwnd;
	}

	void Update()
	{
		if (mbLBtnPush && !(GetAsyncKeyState(VK_LBUTTON) & 0x8000))
		{
			POINT mousePos;
			GetCursorPos(&mousePos);
			ScreenToClient(mHWnd, &mousePos);

			Circle circle;
			circle.CenterX = mousePos.x;
			circle.CenterY = mousePos.y;
			circle.Radius = 50;
			mCircles.PushBack(circle);
		}
		else if (mbRBtnPush && !(GetAsyncKeyState(VK_RBUTTON) & 0x8000))
		{
			for (auto iter = mCircles.Begin(); iter != mCircles.End();)
			{
				POINT mousePos;
				GetCursorPos(&mousePos);
				ScreenToClient(mHWnd, &mousePos);

				float diffX = fabsf(mousePos.x - iter->CenterX);
				float diffY = fabsf(mousePos.y - iter->CenterY);

				if (diffX < iter->Radius && diffY < iter->Radius)
				{
					InvalidateRect(mHWnd, NULL, TRUE);
					iter = mCircles.Erase(iter);
				}
				else
				{
					++iter;
				}
			}
		}

		mbLBtnPush = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
		mbRBtnPush = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
	}

	void Render()
	{
		HDC dc = GetDC(mHWnd);
		SelectObject(dc, GetStockObject(GRAY_BRUSH));

		for (auto iter = mCircles.Begin(); iter != mCircles.End(); ++iter)
		{
			float l = iter->CenterX - iter->Radius;
			float t = iter->CenterY - iter->Radius;
			float r = iter->CenterX + iter->Radius;
			float b = iter->CenterY + iter->Radius;
			Ellipse(dc, l, t, r, b);
		}
	}

	void Release()
	{
		mHWnd = NULL;
		mCircles.Clear();
	}

private:
	HWND mHWnd;
	List<Circle> mCircles;

	bool mbLBtnPush;
	bool mbRBtnPush;
};
