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
		// 여기서 그린다.
		hdc = GetDC(hWnd);

		// 창을 원점 기준으로 맞추면 사각형이 그려지기는 하는데 원점 기준이 아니라 창 위치 기준이여야 하는거 아닌가?
		// 이렇게 그리는 것이 맞나?
		Ellipse(hdc, curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y);

		// 위치 저장해서 linked List 안에 넣자.
		RECT _rect = { curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y };
		linkedList.PushBack(_rect);

		ReleaseDC(hWnd, hdc);

		isDrawing = false;
	}

	if (isRemove)
	{
		// 여기서 포함되어 있는 원을 삭제한다.
		RECT _rect = { curMousepos.x, curMousepos.y, preMousepos.x, preMousepos.y };
		
		const RECT* fillrect = &_rect;
		// 리스트를 돌면서 삭제해야 할 거 같은데? 조건문은?
		// 포함했는데 node가 비어 있는 경우는 넘어가도록 하자.
		
		// 만들 때 좌측 상단 -> 우측 하단으로 만들고 나서 
		// 좌측 상단 -> 우측 하단으로 삭제를 할 때는 정상적으로 삭제가 됩니다.
		// 
		// 하지만 우측 상단 -> 좌측 하단으로 만들고 나서
		// 우측 상단 -> 좌측 하단으로 삭제할 때는 삭제가 되지 않고
		// 좌측 상단 -> 우측 하단으로 삭제할 때 
		// 기존에 만들었던 우측 상단 -> 좌측하단에 들어가서 삭제하다가 없는 node라고 뜨면서 터집니다.
		
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

