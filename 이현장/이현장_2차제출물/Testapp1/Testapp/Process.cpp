#include "Process.h"
#include "Resource.h"

Process::Process(HINSTANCE hInstance, int nCmdShow) : m_hInstance(hInstance), m_msg(), m_nCmdShow(nCmdShow)
{
}

Process::~Process()
{
}

void Process::initialize(WCHAR* title, WCHAR* WindowClass, int index)
{

    LoadStringW(m_hInstance, IDS_APP_TITLE, title, index);
    LoadStringW(m_hInstance, IDC_TESTAPP, WindowClass, index);
    MyRegisterClass(m_hInstance);

    m_hWnd = CreateWindowW(WindowClass, title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInstance, nullptr);

    if (!m_hWnd)
    {
        return;
    }

    ShowWindow(m_hWnd, m_nCmdShow);
    UpdateWindow(m_hWnd);

    m_hAccelTable = LoadAccelerators(m_hInstance, MAKEINTRESOURCE(IDC_TESTAPP));

}

void Process::Loop()
{
    // 기본 메시지 루프입니다:
    while (PeekMessage(&m_msg, m_hWnd, 0, 0, PM_REMOVE))
    {
        if (!TranslateAccelerator(m_msg.hwnd, m_hAccelTable, &m_msg))
        {
            TranslateMessage(&m_msg);
            DispatchMessage(&m_msg);
        }
        else
        {
            Update();
            Render();
        }
    }

}


LRESULT Process::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

ATOM Process::MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TESTAPP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TESTAPP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
