#include "DrawCircle.h"

HDC hdc; //±×¸®±â
PAINTSTRUCT ps;

void DrawCircle::Render(HWND hWnd,int getX, int getY)
{
    hdc = BeginPaint(hWnd, &ps);
    Ellipse(hdc, getX, getY, getX + 100, getY + 100);
    EndPaint(hWnd, &ps);
}
