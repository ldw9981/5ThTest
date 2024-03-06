#include "MyGame.h"

void MyGame::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hdc = GetDC(hWnd);
}

void MyGame::RenderEllipse(POINT mousePos)
{
    // 빨간색 브러시 생성
    HBRUSH hEllipseBrush = CreateSolidBrush(RGB(123, 155, 0));

    // 중심을 기준으로 100x100 크기의 타원을 그림
    Ellipse(m_hdc, mousePos.x - 50, mousePos.y - 50, mousePos.x + 50, mousePos.y + 50);

    // 브러시 삭제
    DeleteObject(hEllipseBrush);
}

void MyGame::Render(POINT mousepos, bool IsMousePressed)
{
    PAINTSTRUCT ps;
    m_hdc = BeginPaint(m_hWnd, &ps);

    if (IsMousePressed)
    {
        RenderEllipse(mousepos);
    }

    EndPaint(m_hWnd, &ps);
}


