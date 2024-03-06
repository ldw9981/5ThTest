#include "framework.h"
#include "AddDeleteCircle.h"
#include "GameLoop.h"

//마우스와 원과의 충돌을 통해 우측버튼이 눌렸을때 마우스가 특정원을 가르키고 있는지 체크

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

GameLoop* gameLoop;
int mousePosx;
int mousePosy;

int count[100];

bool OBBCheck(int circleX, int circleY)
{
    int collisionCheck = 10;

    ////충돌 안함
    if (mousePosx - circleX > collisionCheck && mousePosy - circleY > collisionCheck)
        return false;

    else
        return true;


}
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
    LoadStringW(hInstance, IDC_ADDDELETECIRCLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ADDDELETECIRCLE));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            gameLoop->Update();
         
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ADDDELETECIRCLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ADDDELETECIRCLE);
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

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   gameLoop = new GameLoop(hWnd);

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

int circleCount = 0;
int circleX[100];
int circleY[100];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HBRUSH hBrush;

    switch (message) {
 
    case WM_MOUSEMOVE:
        mousePosx = GET_X_LPARAM(lParam);
        mousePosy = GET_Y_LPARAM(lParam);
        break;

    case WM_LBUTTONDOWN: //왼쪽버튼을 누르면
        hdc = GetDC(hWnd); 
        circleX[circleCount] = mousePosx;
        circleY[circleCount] = mousePosy;
        circleCount++;

        hBrush = CreateSolidBrush(RGB(0, 0, 255));//도형의 색을 선택
        SelectObject(hdc, hBrush); // 그리기 도구 hdc의 색을 지정
        //Rectangle(hdc, mousePosx - 10, mousePosy - 10, mousePosx + 60, mousePosy + 60);// 사각형을 그려라
        Ellipse(hdc, mousePosx - 10, mousePosy - 10, mousePosx + 10, mousePosy + 10);
        break;

    case WM_RBUTTONDOWN: //오른쪽버튼을 누르면
        hdc = GetDC(hWnd);

        for (int i = 0; i < circleCount; i++)
        {
            bool check;
            check = OBBCheck(circleX[i], circleY[i]);

            if (check == true)
            {
                hBrush = CreateSolidBrush(RGB(255, 255, 255));//도형의 색을 선택
                SelectObject(hdc, hBrush); // 그리기 도구 hdc의 색을 지정
                //Rectangle(hdc, mousePosx - 10, mousePosy - 10, mousePosx + 60, mousePosy + 60);// 사각형을 그려라
                Ellipse(hdc, circleX[i] - 10, circleY[i] - 10, circleX[i] + 10, circleY[i] + 10);

            }
        }
        break;

    case WM_PAINT: //최소화하고 다시 그려진다
        hdc = BeginPaint(hWnd, &ps);
        for (int i = 0; i < circleCount; i++) 
        {
            hBrush = CreateSolidBrush(RGB(0, 0, 255));
            SelectObject(hdc, hBrush);
            for(int i = 0; i < circleCount; i++)
                Ellipse(hdc, circleX[i] - 10, circleY[i] - 10, circleX[i] + 10, circleY[i] + 10);
        }
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, message, wParam, lParam));
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


