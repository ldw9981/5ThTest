
///
// 2차 제출물을 제작하면서 list의 iterator와 erase가 필요하다는 것을 깨닫고, 
// 제작하려하였으나 iterator의 구현이 막히고 시간이 얼마 남지않아서 제출하게 되었습니다.
///

#include "framework.h"
#include "KimJaeHyeon2.h"
#include <windowsx.h>
#include <iostream>

template<typename T>
class Node
{
public:
    Node() {};
    Node(T _Data) { data = _Data; }

public:
    Node* prev = nullptr;
    Node* next = nullptr;
    T data = {};
    int m_index = 0;

};

template<typename T>
class myList
{
private:
    Node<T>* cur;

public:
    Node<T>* tail;
    Node<T>* head;
    int num = 0;

public:
    Node<T> front()
    {
        return *head->next;
    }

    Node<T> end()
    {
        return *tail->prev;
    }
    int size()
    {
        return num;
    }

    int GetIndex()
    {
        return cur->m_index;
    }

    Node<T>* GetCurNode()
    {
        return cur;
    }

    void SetCurNode(Node<T>& curNode)
    {
        curNode = cur;
    }

    void NextNode()
    {
        if (cur->next != nullptr)
            cur = cur->next;
    }

    void erase(int index)
    {
        if (cur->m_index = index)
        {
            cur->next = cur->prev->next;
            cur->prev = cur->next->prev;
            delete cur;
        }
    }

    void push_back(T instance)
    {
        if (num == 0)
        {
            Node<T>* element = new Node<T>(instance);
            Node<T>* myHead = new Node<T>();
            Node<T>* myTail = new Node<T>();

            head = myHead;
            tail = myTail;

            head->next = element;
            tail->prev = element;

            element->next = tail;
            element->prev = head;

            num++;
        }
        else
        {
            Node<T>* element = new Node<T>(instance);

            element->prev = tail->prev;
            element->next = tail;

            tail->prev->next = element;
            tail->prev = element;
            num++;
        }
    }

    void pop()
    {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        num--;
    }
};

struct CircleData
{
public:
    int top;
    int bottom;
    int left;
    int right;
};

myList<CircleData> myCircleList;
HWND myHwnd;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_KIMJAEHYEON2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KIMJAEHYEON2));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (true) {
        // 메시지 처리
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            ///

            // 게임 업데이트 
            for (int i = 0; i < myCircleList.size(); i++)
            { 
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(myHwnd, &ps);

           //     auto curNode = myCircleList.GetCurNode();
           //     Ellipse(hdc, curNode->data.left, curNode->data.top, curNode->data.right, curNode->data.bottom);
           //     myCircleList.NextNode();
                EndPaint(myHwnd, &ps);
            }

            ///
        }
    }


    return (int) msg.wParam;
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KIMJAEHYEON2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_KIMJAEHYEON2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   myHwnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
    case WM_LBUTTONDOWN:
    {
        HDC hdc = GetDC(myHwnd);
        Ellipse(hdc, GET_X_LPARAM(lParam) - 25, GET_Y_LPARAM(lParam) - 25, GET_X_LPARAM(lParam) + 25, GET_Y_LPARAM(lParam) + 25);
        CircleData circle{ GET_X_LPARAM(lParam) - 25, GET_Y_LPARAM(lParam) - 25, GET_X_LPARAM(lParam) + 25, GET_Y_LPARAM(lParam) + 25 };
        myCircleList.push_back(circle);
        ReleaseDC(myHwnd, hdc);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        HDC hdc = GetDC(myHwnd);
        Ellipse(hdc, GET_X_LPARAM(lParam) - 25, GET_Y_LPARAM(lParam) - 25, GET_X_LPARAM(lParam) + 25, GET_Y_LPARAM(lParam) + 25);
        ReleaseDC(myHwnd, hdc);
        InvalidateRect(myHwnd, NULL, TRUE); // 화면 갱신 요청

        break;
    }
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
