#include "GameProcess.h"

GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

void GameProcess::Initialize(HWND _hWnd)
{
	hWnd = _hWnd;
}

void GameProcess::Update()
{
	// 마우스 클릭을 인지하는 부분

	if (GetAsyncKeyState(WM_LBUTTONDOWN & 0x8001))
	{		
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);
		Circle circle = Circle(hWnd, mousePos.x - 10, mousePos.y - 10, mousePos.x + 10, mousePos.y + 10);
		circles.PushBack(circle);
	}

	/// 왜 이거 인식이 안 되는지 모르겠다...
	if (GetAsyncKeyState(WM_RBUTTONDOWN & 0x8000))
	{
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);
		for (auto iter = circles.Begin(); iter != circles.End(); ++iter)
		{
			Circle& curCircle = (*iter)->data;
			if (curCircle.left >= mousePos.x - 10 &&
				curCircle.top >= mousePos.y - 10 &&
				curCircle.right <= mousePos.x + 10 &&
				curCircle.bottom <= mousePos.y + 10)
			{
				curCircle.DeleteCircle();
			}
		}
	}
}

void GameProcess::Render()
{
	for (auto iter = circles.Begin(); iter != circles.End(); ++iter)
	{
		(*iter)->data.Render();
	}
}

void GameProcess::Finalize()
{
	circles.Clear();
}
