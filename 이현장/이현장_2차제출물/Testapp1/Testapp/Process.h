#pragma once
#include <windows.h>
class Process
{
public:
	Process(HINSTANCE hInstance, int nCmdShow);
	~Process();

public:
	void initialize(WCHAR* title, WCHAR* m_szWindowClass ,int index);
	void Loop();
	void Render();
	void Update();

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM MyRegisterClass(HINSTANCE hInstance);
public:

private:
	WCHAR* m_szTitle;
	WCHAR* m_szWindowClass;
	MSG m_msg;
	HINSTANCE m_hInstance;
	int m_nCmdShow;
	HACCEL m_hAccelTable;
	HWND m_hWnd;
};

