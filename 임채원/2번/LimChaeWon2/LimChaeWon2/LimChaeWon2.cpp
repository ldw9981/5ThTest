#include <windows.h>
#include "MyLinkedList.h"

struct Point
{
    float x;
    float y;
};

MyLinkedList<Point> mll;

void Render(HWND& hWnd)
{
    HDC hdc;
    hdc = GetDC(hWnd);

    MyLinkedList<Point>::Node* curNode = mll.GetHead();
    if (!curNode)
    {
        // 화면 클리어
    }
    
    while (curNode)
    {
        int x = curNode->data.x;
        int y = curNode->data.y;
        Ellipse(hdc, x - 100, y - 100, x + 100, y + 100);
        curNode = curNode->next;
    }

}

void Update(float deltaTime)
{
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWinAPI");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, (HMENU)NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    LARGE_INTEGER m_nPrevCnt;
    LARGE_INTEGER m_nFrequency;
    LARGE_INTEGER m_nCurCnt;

    QueryPerformanceCounter(&m_nPrevCnt);
    QueryPerformanceFrequency(&m_nFrequency);

    while (true)
    {
        if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
        {
            if (Message.message == WM_QUIT)
            {
                break;
            }
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
        else
        {
            QueryPerformanceCounter(&m_nCurCnt);
            float deltaTime = (m_nCurCnt.QuadPart - m_nPrevCnt.QuadPart) / (float)m_nFrequency.QuadPart;
            m_nPrevCnt = m_nCurCnt;
            Render(hWnd);
            Update(deltaTime);
        }
    }

    return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
    WPARAM wParam, LPARAM lParam)
{
    
    PAINTSTRUCT ps;
    HBRUSH hBrush;
    Point p;
    switch (iMessage)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_LBUTTONDOWN:
        p.x = LOWORD(lParam);
        p.y = HIWORD(lParam);

        mll.PushBack(p);
        return 0;

    case WM_RBUTTONDOWN:
        mll.EraseAll();
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}