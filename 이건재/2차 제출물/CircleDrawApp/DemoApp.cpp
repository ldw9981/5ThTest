#include "DemoApp.h"

#include "Circle.h"

DemoApp::DemoApp()
{
}

DemoApp::~DemoApp()
{
}

void DemoApp::SetHWND(HWND hwnd)
{
    m_hwnd = hwnd;
}

void DemoApp::Init()
{
    hBrush = CreateSolidBrush(RGB(255, 0, 0));
}

void DemoApp::Update()
{
}

void DemoApp::Render()
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(m_hwnd, &ps);
    // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

    SelectObject(hdc, hBrush);

    // ���� �������µ� �ȱ׷����׿�; �Ф�
    for (int i = 0; i < m_Circles.NodeSize; i++)
    {
        Circle circle = m_Circles.Find(i)->m_Data;

        Ellipse(hdc
            , circle.m_Center.x - circle.m_Radius
            , circle.m_Center.y - circle.m_Radius
            , circle.m_Center.x + circle.m_Radius
            , circle.m_Center.y + circle.m_Radius);
    }

    Ellipse(hdc
        , 0.f
        , 100.f
        , 100.f
        , 200.f);


    EndPaint(m_hwnd, &ps);
}

void DemoApp::CreateCircle()
{
    Circle circle(Vector2{ static_cast<float>(MouseX), static_cast<float>(MouseY) });

    m_Circles.PushFront(circle);
}

void DemoApp::DeleteCircle()
{
    // �������� �Ǵ°� Ȯ���ߴµ�..
    for (int i = 0; i < m_Circles.GetSize(); i++)
    {
        Circle circle = m_Circles.Find(i)->m_Data;

        if (circle.m_Center.x - circle.m_Radius < MouseX
            && circle.m_Center.x + circle.m_Radius > MouseX
            && circle.m_Center.y - circle.m_Radius < MouseY
            && circle.m_Center.y + circle.m_Radius > MouseY)
        {
            m_Circles.eraser(m_Circles.Find(i));
        }
    }
}
