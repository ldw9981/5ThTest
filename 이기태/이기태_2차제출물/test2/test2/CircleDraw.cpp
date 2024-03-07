#include "CircleDraw.h"
#include <cmath>

void CircleDraw::Initialize()
{
	mainDC = GetDC(hwnd);
	memDC = CreateCompatibleDC(mainDC);


}

void CircleDraw::Finalize()
{
	DeleteDC(memDC);
}

void CircleDraw::Update()
{
	// Input 
	UpdateMousePosition();

	bool lMouse = GetAsyncKeyState(VK_LBUTTON);
	bool rMouse = GetAsyncKeyState(VK_RBUTTON);

	// 게임 로직
	if (!prevLMouse && lMouse)
	{
		AddCircle(mousePosX, mousePosY, circleRadius);
	}

	if (!prevRMouse && rMouse)
	{
		DeleteCircles(mousePosX, mousePosY);
	}

	prevLMouse = lMouse;
	prevRMouse = rMouse;
}

void CircleDraw::Render()
{
	//현재 윈도우 창 크기 받아오기
	RECT rect;
	GetClientRect(hwnd, &rect);

	HBITMAP memBitmap = CreateCompatibleBitmap(memDC, rect.right, rect.bottom);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

	// 화면 지우기
	FillRect(memDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

	for (const auto& circle : circleList)
	{
		float circleX = circle.GetX();
		float circleY = circle.GetY();
		float radius = circle.GetRadius();

		// 원그리기 
		Ellipse(memDC,
			static_cast<int>(circleX - radius),
			static_cast<int>(circleY - radius),
			static_cast<int>(circleX + radius),
			static_cast<int>(circleY + radius));
	}

	BitBlt(mainDC, 0, 0, rect.right, rect.bottom, memDC, 0, 0, SRCCOPY);
	SelectObject(memDC, oldBitmap);
	DeleteObject(memBitmap);
}

void CircleDraw::AddCircle(float x, float y, float radius)
{
	circleList.push_back(Circle(x, y, radius));
}

void CircleDraw::DeleteCircles(float x, float y)
{
	constexpr float radiusSquare = circleRadius * circleRadius;

	for (auto iter = circleList.begin(); iter != circleList.end();)
	{
		float r = (*iter).GetRadius();
		float circleX = (*iter).GetX();
		float circleY = (*iter).GetY();

		float distanceSq = (x - circleX) * (x - circleX) + (y - circleY) * (y - circleY);

		if (distanceSq <= radiusSquare)
		{
			iter = circleList.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void CircleDraw::UpdateMousePosition()
{
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(hwnd, &pos);

	mousePosX = static_cast<float>(pos.x);
	mousePosY = static_cast<float>(pos.y);
}
