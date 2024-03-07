#pragma once
#include <windows.h>
#include "LinkedList.h"

struct Circle
{
	int x, y;
};
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();
	void DrawCircle(int x, int y);
	void DeleteCircle(int x, int y);
public:
	HWND m_hwnd;
	HDC m_hdc;
	
	HDC m_backBuffer;
	HBITMAP m_hBitmap;
	// mousePos
	POINT m_mousePos;

	LinkedList<Circle> m_circles;

	PAINTSTRUCT ps;

	HBRUSH m_brush;
	/*HBRUSH m_drawBrush;
	HBRUSH m_drawOldBrush;*/
};

