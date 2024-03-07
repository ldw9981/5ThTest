#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::Initailze(HWND _hWnd )
{
	hWnd = _hWnd;
}

void Renderer::Render()
{
	if (isDrawing)
	{
		// ���⼭ �׸���.
		hdc = GetDC(hWnd);

		// â�� ���� �������� ���߸� �簢���� �׷������ �ϴµ� ���� ������ �ƴ϶� â ��ġ �����̿��� �ϴ°� �ƴѰ�?
		// �̷��� �׸��� ���� �³�?
		Ellipse(hdc, curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y);

		// ��ġ �����ؼ� linked List �ȿ� ����.
		RECT _rect = { curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y };
		linkedList.PushBack(_rect);

		ReleaseDC(hWnd, hdc);

		isDrawing = false;
	}

	if (isRemove)
	{
		// ���⼭ ���ԵǾ� �ִ� ���� �����Ѵ�.
		RECT _rect = { curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y };
		
		const RECT* fillrect = &_rect;
		// ����Ʈ�� ���鼭 �����ؾ� �� �� ������? ���ǹ���?
		// �����ߴµ� node�� ��� �ִ� ���� �Ѿ���� ����.
		
		// ���� �� ���� ��� -> ���� �ϴ����� ����� ���� 
		// ���� ��� -> ���� �ϴ����� ������ �� ���� ���������� ������ �˴ϴ�.
		// 
		// ������ ���� ��� -> ���� �ϴ����� ����� ����
		// ���� ��� -> ���� �ϴ����� ������ ���� ������ ���� �ʰ�
		// ���� ��� -> ���� �ϴ����� ������ �� 
		// ������ ������� ���� ��� -> �����ϴܿ� ���� �����ϴٰ� ���� node��� �߸鼭 �����ϴ�.
		
		DoubleLinkedList<RECT>::Node* node = linkedList.Find(_rect);
		while (node != nullptr)
		{
			linkedList.Remove(node);
			hdc = GetDC(hWnd);
			HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
			FillRect(hdc, fillrect, brush);
			ReleaseDC(hWnd, hdc);
			node = linkedList.Find(_rect);
		}
		isRemove = false;
	}
}

