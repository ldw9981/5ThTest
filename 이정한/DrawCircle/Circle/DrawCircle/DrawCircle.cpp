// DrawCircle.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "DrawCircle.h"

#include "../LinkedList/LinkedList.h"
#include "MyGame.h"

#define MAX_LOADSTRING 100
#define CURRENT_WND_CLASS _T("GameWndClass")

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

bool g_MouseButtonDown = false;
POINT mouse;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, char*, int) {
    WNDCLASSEXA win = { 0 };
    win.cbSize = sizeof(win);
    win.style = CS_HREDRAW | CS_VREDRAW;
    win.hInstance = hinstance;
    win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    win.lpszClassName = "my window";
    win.lpfnWndProc = WndProc; //나중에 배움
    RegisterClassExA(&win);
    HWND hwnd;
    hwnd = CreateWindowA(
        "my window",
        "DrawCircle",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0, 0, hinstance, 0
    );
    ShowWindow(hwnd, 1);
    UpdateWindow(hwnd);

    MyGame* Game = new MyGame();

    Game->Init(hwnd);

    MSG msg;
    while (true) {
        if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);

        }
        else {
            Game->Render(mouse, g_MouseButtonDown);
        }
    }

    delete Game;
    DestroyWindow(hwnd);
    UnregisterClass(CURRENT_WND_CLASS, hInst);

    return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;

    switch (message)
    {
    case WM_LBUTTONDOWN: {
        g_MouseButtonDown = true;
        mouse.x = LOWORD(lParam);
        mouse.y = HIWORD(lParam);
        InvalidateRect(hWnd, NULL, FALSE);
        break;
    }
    case WM_LBUTTONUP: {
        g_MouseButtonDown = false;
        InvalidateRect(hWnd, NULL, FALSE);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
