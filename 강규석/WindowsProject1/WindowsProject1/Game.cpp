#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	// 브러쉬 
	DeleteObject(m_brush);
}

void Game::Init(HWND hwnd)
{
	m_hwnd = hwnd;
	m_hdc = GetDC(hwnd);

	// dubble buffering
	m_backBuffer = CreateCompatibleDC(m_hdc);
	m_hBitmap = LoadBitmap(NULL, MAKEINTRESOURCE(m_backBuffer));
	m_brush = CreateSolidBrush(RGB(255, 255, 255));
}

void Game::Update()
{
	::GetCursorPos(&m_mousePos);
	::ScreenToClient(m_hwnd, &m_mousePos);
	//if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)

	static float coolTime = 0.3f;
	float time = 0.2f;
	coolTime += 0.01f;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (coolTime > time)
		{
			coolTime = 0.f;
			Circle c;
			c.x = m_mousePos.x;
			c.y = m_mousePos.y;
			m_circles.push_back(c);
		}
	}
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		DeleteCircle(m_mousePos.x, m_mousePos.y);
	}
}

void Game::Render()
{
	RECT rect;
	GetClientRect(m_hwnd, &rect);

	HDC hdc = GetDC(m_hwnd);
	m_backBuffer = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_backBuffer, hBitmap);
	FillRect(m_backBuffer, &rect, m_brush);
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, m_backBuffer, 0, 0, SRCCOPY);

	for (auto it = m_circles.begin(); it != m_circles.end(); it++)
	{
		Circle c = *it;
 		DrawCircle(c.x, c.y);
	}
	
	SelectObject(m_backBuffer, hOldBitmap);
	ReleaseDC(m_hwnd, m_backBuffer);
	ReleaseDC(m_hwnd, hdc);

}

void Game::DrawCircle(int x, int y)
{
	HDC hdc = m_backBuffer;
	HPEN hBrush = CreatePen(PS_SOLID, 4.f,RGB(255, 0, 0)); // 빨간색 Brush 객체 생성.
	HPEN hOldBrush = (HPEN)SelectObject(hdc,hBrush); 	// 새로 만든 Brush 객체로 교체.

	float radius = 30.f;
	float left		= x - radius;
	float top		= y - radius;
	float right		= x + radius;
	float bottom	= y + radius;

	Ellipse(m_hdc, left, top, right, bottom);
	SelectObject(hdc, hOldBrush);
}

void Game::DeleteCircle(int x, int y)
{
	for (auto it = m_circles.begin(); it != m_circles.end(); it++)
	{
		Circle c = *it;

		bool erase = ((x - c.x) * (x - c.x)) + ((y - c.y) * (y - c.y)) < 30.f * 30.f;
		if (erase)
		{
			m_circles.erase(it);
			it = m_circles.begin();
		}
	}
}
