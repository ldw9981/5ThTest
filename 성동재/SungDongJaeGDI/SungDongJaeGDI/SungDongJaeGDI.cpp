#include <windows.h>
#include "myList.h"
POINT mousePos;
int radius = 50;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 윈도우 클래스 등록
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"EllipseWindowClass";

    RegisterClass(&wc);

    // 윈도우 생성
    HWND hwnd = CreateWindowEx(
        0,
        L"EllipseWindowClass",
        L"Ellipse Example",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (hwnd == NULL)
    {
        return 0;
    }

    // 윈도우 표시
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 메시지 처리
    MSG msg;
    MyList<POINT> myList;
    while (true)
    {
        // 메시지가 있으면 처리, 없으면 다음 단계로 진행
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 화면을 지우고 원을 그리는 로직 추가
            HDC hdc = GetDC(hwnd);
            RECT rect;
            GetClientRect(hwnd, &rect);
           // FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH)); // 화면을 흰색으로 지우기
            if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
            {
                myList.push_back(new Node<POINT>(mousePos));
            }
            Node<POINT>* target = myList.startNode->nextNode;
            for (int i = 0; i < myList.size; i++)
            {
                Ellipse(hdc, target->data.x - radius, target->data.y - radius, target->data.x + radius, target->data.y + radius); // 원 그리기
                target = target->nextNode;
            }
            if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
            {
                myList.clear();
                FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH)); // 화면을 흰색으로 지우기
            }
            ReleaseDC(hwnd, hdc);
        }
    }

    return msg.wParam;
}

// 윈도우 프로시저
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_MOUSEMOVE:
        // 마우스가 움직일 때마다 현재 위치 업데이트
        mousePos.x= LOWORD(lParam);
        mousePos.y = HIWORD(lParam);
        // 윈도우를 다시 그리도록 강제로 WM_PAINT 메시지를 보냄
        //InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        // 윈도우 크기가 변경되었을 때 처리할 작업을 수행합니다.
        // 여기서는 InvalidateRect를 호출하여 윈도우를 다시 그리도록 강제합니다.
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(GetDC(hwnd), &rect, (HBRUSH)GetStockObject(WHITE_BRUSH)); // 화면을 흰색으로 지우기
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}