#include "GameProcess.h"
#include "GameObject.h"
#include "Input.h"

GameProcess::~GameProcess()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

void GameProcess::Initailize(HWND hWnd)
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
	m_hWnd = hWnd;
	m_hDC = GetDC(m_hWnd);
	Input::GetInstance().Initailize();

	RECT    rcCli;
	GetClientRect(WindowFromDC(m_hDC), &rcCli);
	// then you might have: 
	auto nWidth = rcCli.right - rcCli.left;
	auto nHeight = rcCli.bottom - rcCli.top;

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, nWidth, nHeight);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);
}

void GameProcess::Update()
{
	Input::GetInstance().Update();
	ScreenToClient(m_hWnd, &Input::GetInstance().mousePos);


	if (Input::GetInstance().GetKeyDown(0))
	{
		auto pos = Input::GetInstance().GetMousePos();
		GameObject* go = new GameObject;
		go->Position = pos;
		go->m_DefferdDestroyer = &m_DefferdDestroyer;
		m_Scene.push_back(go);
	}

	auto iter = m_Scene.begin();
	for (; iter != m_Scene.end(); ++iter)
	{
		(*iter)->Update(0.0167f);
	}
}

void GameProcess::Render()
{
	RECT    rcCli;
	GetClientRect(WindowFromDC(m_hDC), &rcCli);
	// then you might have: 
	auto nWidth = rcCli.right - rcCli.left;
	auto nHeight = rcCli.bottom - rcCli.top;

	auto iter = m_Scene.begin();
	for (; iter != m_Scene.end(); ++iter)
	{
		(*iter)->Render(m_memDC);
	}


	BitBlt(m_hDC, 0, 0, nWidth, nHeight,
		m_memDC, 0, 0, SRCCOPY);

	Rectangle(m_memDC, -1, -1, nWidth + 1, nHeight + 1);

}
