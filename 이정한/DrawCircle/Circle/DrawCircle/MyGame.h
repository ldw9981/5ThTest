#pragma once
#include <Windows.h>
class MyGame
{
public:
	MyGame() {}
	~MyGame() {}

public:
	void Init(HWND hWnd);
	void RenderEllipse(POINT mousePos);
	void Render(POINT mousepos, bool IsMousePressed);
private:
	HWND m_hWnd = {};
	HDC m_hdc = {};
};

