#include "framework.h"
#include <math.h>
#include "LinkedList.h"
#include "2ndProject.h"


POINT mousePos;
int radius = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
float Distance(int x1, int y1, int x2, int y2);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"2ndTest";

	RegisterClass(&wc);

	// 애플리케이션 초기화를 수행합니다:
	HWND hWnd = CreateWindowEx(
		0, L"2ndTest", L"제발 잘 좀 되라..",
		WS_OVERLAPPEDWINDOW, 0, 0, 1080, 1920, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2NDPROJECT));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	LinkedList<POINT> list;

	switch (message)
	{
	case WM_PAINT:
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		// 화면을 지우는 작업
		RECT rect;
		GetClientRect(hWnd, &rect);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		mousePos.x = LOWORD(lParam); // 마우스의 X 좌표 가져오기
		mousePos.y = HIWORD(lParam); // 마우스의 Y 좌표 가져오기
		break;

	case WM_LBUTTONDOWN:
		list.PushBack(mousePos);

		hdc = GetDC(hWnd);
		for (auto iter = list.Begin(); iter != list.End(); ++iter)
		{
			Ellipse(hdc, (*iter).x - radius, (*iter).y - radius, (*iter).x + radius, (*iter).y + radius);
		}
		ReleaseDC(hWnd, hdc);

		break;

	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);
		POINT tempMousePos = mousePos;
		//Ellipse(hdc, tempMousePos.x - radius, tempMousePos.y - radius, tempMousePos.x + radius, tempMousePos.y + radius);

		for (auto iter = list.Begin(); iter != list.End(); ++iter)
		{
			if (Distance(tempMousePos.x, (*iter).x, tempMousePos.y, (*iter).y) <= static_cast<float>(radius))
			{
				//list.eraseNode(*iter);
			}
		}
		ReleaseDC(hWnd, hdc);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

float Distance(int x1, int y1, int x2, int y2)
{
	return std::sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}