#include "MyGame.h"

void MyGame::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hdc = GetDC(hWnd);
}

void MyGame::RenderEllipse(POINT mousePos)
{
    // ������ �귯�� ����
    HBRUSH hEllipseBrush = CreateSolidBrush(RGB(123, 155, 0));

    // �߽��� �������� 100x100 ũ���� Ÿ���� �׸�
    Ellipse(m_hdc, mousePos.x - 50, mousePos.y - 50, mousePos.x + 50, mousePos.y + 50);

    // �귯�� ����
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


