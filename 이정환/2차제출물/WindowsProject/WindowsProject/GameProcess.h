#pragma once
#include <windows.h>
#include "MouseManager.h"

// ������۸��ؾߵ����ʳ�

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

