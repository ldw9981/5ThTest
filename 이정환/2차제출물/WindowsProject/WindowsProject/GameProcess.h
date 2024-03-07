#pragma once
#include <windows.h>
#include "MouseManager.h"

// 더블버퍼링해야되지않나

class GameProcess
{
public:
	GameProcess();
	~GameProcess();

public:
	void Init(HWND hwnd, HINSTANCE hInst, HDC hdc);
	void Update(WPARAM wParam, LPARAM lParam);
	void Render();

	void Release();

private:
	HWND m_hWnd;

	HDC m_hdc;

};

