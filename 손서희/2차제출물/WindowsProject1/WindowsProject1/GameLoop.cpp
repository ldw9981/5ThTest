#include "Windows.h"
#include "GameLoop.h"
#include <cmath>

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
	ReleaseDC(m_hwnd, m_hdc);
	DeleteDC(m_memDC);
	DeleteObject(m_bitmap);
}

void GameLoop::Start(HWND hwnd)
{
	m_hwnd = hwnd;

	RECT rt = { 0,0,1000, 600 };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	m_hdc = GetDC(m_hwnd);

	//더블버퍼링
	m_bitmap = CreateCompatibleBitmap(m_hdc, 1000, 600);
	m_memDC = CreateCompatibleDC(m_hdc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_bitmap);
	DeleteObject(hOldBit);

}

void GameLoop::Render()
{
	//화면 초기화
	Rectangle(m_memDC, -1, -1, 1000+1, 600 + 1);

	for (int i = 0; i < m_circleCount; i++) {
		m_circles.Get(i).Render(m_memDC);
	}

	BitBlt(m_hdc, 0, 0, 1000, 600, m_memDC, 0,0,SRCCOPY);
}

void GameLoop::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		m_iscurrLB = true;
	}
	else m_iscurrLB = false;

	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)  // 지워지기
	{
		m_iscurrRB = true;
	}
	else m_iscurrRB = false;

	POINT mousePos;
	GetCursorPos(&mousePos);
	ScreenToClient(m_hwnd, &mousePos);

	if (!m_isprevLB && m_iscurrLB) // 그려지기
	{
		m_circles.PushBack(MyCircle(mousePos));
		m_circleCount++;
	}

	if (!m_isprevRB && m_iscurrRB) // 지워지기
	{
		for (int i = 0; i < m_circleCount; i++) 
		{
			MyCircle cir = m_circles.Get(i);
			float dist = Distance(cir.m_position, mousePos);
			if (dist < 50)
			{
				m_circles.Erase(i);
				i--;
				m_circleCount--;
			}
		}
	}


	m_isprevLB = m_iscurrLB;
	m_isprevRB = m_iscurrRB;
}

void GameLoop::Finalize()
{
}

float GameLoop::Distance(POINT p1, POINT p2)
{
	float xx = (p1.x - p2.x) * (p1.x - p2.x);
	float yy = (p1.y - p2.y) * (p1.y - p2.y);
	return sqrt(xx + yy);
}
