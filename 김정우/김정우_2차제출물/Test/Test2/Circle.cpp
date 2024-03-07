#include "Circle.h"
#include <wingdi.h>


Circle::Circle(HWND hWnd, float left, float top, float right, float bottom)
	: hWnd(hWnd), left(left), top(top), right(right), bottom(bottom)
{

}

void Circle::DeleteCircle()
{
	isDeleted = true;
}

void Circle::Render()
{
	if (!isDeleted)
	{
		HDC hdc = GetDC(hWnd);

		HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = reinterpret_cast<HBRUSH>(SelectObject(hdc, myBrush));
		Ellipse(hdc, left, top, right, bottom);
		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

		ReleaseDC(hWnd, hdc);
	}
}
