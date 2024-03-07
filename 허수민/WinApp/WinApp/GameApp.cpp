#include "pch.h"
#include "GameApp.h"

void GameApp::Init(HWND hwnd, POINT resolution)
{
	m_hWnd = hwnd;
	m_resolution = resolution;

	RECT windowRect = { 0, 0, resolution.x, resolution.y };
	::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(m_hWnd, NULL, 0, 0,
		windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL);
}

void GameApp::Update()
{
}

void GameApp::Render()
{
}
