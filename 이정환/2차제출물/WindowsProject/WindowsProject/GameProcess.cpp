#include "GameProcess.h"
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")

#include "SingleTon.h"
#include "MouseManager.h"


using namespace Gdiplus;

GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

void GameProcess::Init(HWND hwnd, HINSTANCE hInst, HDC hdc)
{
	m_hWnd = hwnd;
	m_hdc = hdc;

}

void GameProcess::Update(WPARAM wParam, LPARAM lParam)
{

}

void GameProcess::Render()
{
	Graphics graphics(m_hdc);
	Pen BluePen(Color(255, 0, 0, 255));

	graphics.DrawLine(&BluePen, Point(10, 10), Point(200, 200));
	graphics.DrawEllipse(&BluePen, 200, 10, 10, 200);
}

void GameProcess::Release()
{
	
}
