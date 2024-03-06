#include "framework.h"
#include "Project1.h"
#include "LinkedList.h"

#include<WinUser.h>


#define MAX_LOADSTRING 100


HINSTANCE hInst;                               
WCHAR szTitle[MAX_LOADSTRING];                
WCHAR szWindowClass[MAX_LOADSTRING];         


LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);



struct Circle
{
    //중심
    POINT pos;

    //반지름
    double radius;

    Circle()
    {

    }

    Circle(POINT position) : pos(position), radius(5)
    {

    }
};


LinkedList<Circle> CircleList;

void Update()
{
    //왼버튼 클릭시 그리기
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
       //원을 그리고 링크드 리스트에 넣기
       //노드는 원의 중심 좌표와 반지름을 갖고 있는 원의 구조체를 갖고 있어야한다

        POINT mous;
        GetCursorPos(&mous);

        CircleList.Push_back(Circle(mous));

    }

    if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
    {
        //우클릭 해당 마우스 포인터랑 원의 중심이랑 거리 확인해서 링크드 리스트에서 제외

        POINT mous;
        GetCursorPos(&mous);


        Node<Circle>* temp = CircleList.GetHead();
        int count = 1;
        while (temp != nullptr)
        {
            //마우스가 찍은 점이 원 내부에 있다면
            if ((temp->data.pos.x - mous.x) * (temp->data.pos.x - mous.x) + (temp->data.pos.y - mous.y) * (temp->data.pos.y - mous.y)
                < temp->data.radius * temp->data.radius)
            {
                //링크드리스트에서 제거
                CircleList.Pop(count);
            }

            temp = temp->next;
            count++;
        }
        
        
    }
}


void Render(HWND hWnd)
{
    PAINTSTRUCT ps;

   //링크드 리스트에 있는 애들은 계속 그리게 둔다
    BeginPaint(hWnd,&ps);

    Node<Circle>* temp = CircleList.GetHead();
    while (temp != nullptr)
    {
        //그리기 함수 필요
        Ellipse(GetDC(hWnd), temp->data.pos.x - temp->data.radius, temp->data.pos.y - temp->data.radius, temp->data.pos.x + temp->data.radius, temp->data.pos.y + temp->data.radius);

        temp = temp->next;
    }

    EndPaint(hWnd,&ps);
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);


    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PROJECT1);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    if (!RegisterClassExW(&wcex))
    {
        return false;
    }


    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);


    MSG msg;

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //프레임이 너무 빠르다
        Update();
        Render(hWnd);
  
    }

    return (int) msg.wParam;
}



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