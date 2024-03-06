#include "GameProcess.h"

void GameProcess::Init(HWND _hWnd)
{
	// 뭔가 초기화 한다.
	m_hWnd = _hWnd;
}

void GameProcess::Update()
{
	// 뭔가 업데이트 한다
	// 1 커서위치를 업데이트한다.
	GetCursorPos(&m_mousePos);
	// 2 클릭을 하면 커서위치를 이용해 오브젝트를 생성한다.
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_object = new Object(m_mousePos);
	}
	// 3 생성된 오브젝트를 리스트에 넣자.

	if (GetAsyncKeyState(VK_RBUTTON))
	{
		delete m_object;
		m_object = nullptr;
	}

}

void GameProcess::BeginRender(HDC _dc)
{
	RECT _rect;
	GetClientRect(m_hWnd, &_rect);
	PatBlt(_dc, 0, 0, _rect.right, _rect.bottom, WHITENESS);

}

void GameProcess::Render(HDC _dc)
{
	// 뭔가 그린다.
	if (m_object != nullptr)
	{
		m_object->Render(_dc);
	}
}

void GameProcess::EndRender(HDC _dc)
{
}

