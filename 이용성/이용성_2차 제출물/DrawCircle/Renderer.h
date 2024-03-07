#pragma once
#include <Windows.h>
#include "DoubleLinkedList.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Initailze(HWND _hWnd);
	void Render();

	// Mouse Getter Setter
	void SetPreMousePos(POINT _val) { preMousepos = _val; }
	void SetCurMousePos(POINT _val) { curMousepos = _val; }
	
	void SetIsDrawing(bool _val) { isDrawing = _val; }
	void SetIsRemove(bool _val) { isRemove = _val; }

private:
	HWND hWnd;
	HDC hdc;

	bool isDrawing;
	bool isRemove;

	DoubleLinkedList<RECT> linkedList;

	// 마우스 위치 받아오기
	POINT preMousepos;	// 이전 마우스 위치
	POINT curMousepos;	// 현재 마우스 위치
};

