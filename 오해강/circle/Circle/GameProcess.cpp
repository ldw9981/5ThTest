#include "GameProcess.h"

void GameProcess::Init(HWND _hWnd)
{
	// ���� �ʱ�ȭ �Ѵ�.
	m_hWnd = _hWnd;
}

void GameProcess::Update()
{
	// ���� ������Ʈ �Ѵ�
	// 1 Ŀ����ġ�� ������Ʈ�Ѵ�.
	GetCursorPos(&m_mousePos);
	// 2 Ŭ���� �ϸ� Ŀ����ġ�� �̿��� ������Ʈ�� �����Ѵ�.
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_object = new Object(m_mousePos);
	}
	// 3 ������ ������Ʈ�� ����Ʈ�� ����.

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
	// ���� �׸���.
	if (m_object != nullptr)
	{
		m_object->Render(_dc);
	}
}

void GameProcess::EndRender(HDC _dc)
{
}

