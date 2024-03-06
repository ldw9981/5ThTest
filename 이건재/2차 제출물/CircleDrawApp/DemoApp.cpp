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
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

    SelectObject(hdc, hBrush);

    // 뭔가 들어와지는데 안그려지네요; ㅠㅠ
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
    // 삭제까지 되는건 확인했는데..
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
