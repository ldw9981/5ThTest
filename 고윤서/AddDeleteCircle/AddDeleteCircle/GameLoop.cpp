#include "GameLoop.h"

GameLoop::GameLoop(HWND _hWnd)
	:hWnd(_hWnd)
{
	
		
}

GameLoop::~GameLoop()
{

}

void GameLoop::Init()
{

}



void GameLoop::Render()
{

	//PAINTSTRUCT ps;
	//HDC hdc = BeginPaint(hWnd, &ps);

	////원 그리자
	//if (isCircleDraw == true)
	//{
	//	//원 그리고 다시 false
	//	Ellipse(hdc, mousePointx - 10, mousePointy - 10, mousePointx + 10, mousePointy + 10);
	//	isCircleDraw = false;
	//}

	//EndPaint(hWnd, &ps);
}

void GameLoop::Update()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (isLeftMouseClick == true)
	{
		DrawCircle();
	}
}

void GameLoop::DrawCircle()
{
	isCircleDraw = true;
	isLeftMouseClick = false;
}

void GameLoop::DeleteCircle()
{
}

void GameLoop::CheckOBB()
{
}
