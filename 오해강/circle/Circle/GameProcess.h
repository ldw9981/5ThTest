#pragma once
#include "windows.h"
#include "LinkedList.h"
#include "Object.h"

class Object;

class GameProcess
{
public:
	void Init(HWND _hWnd);
	void Update();

	void BeginRender(HDC _dc);
	void Render(HDC _dc);
	void EndRender(HDC _dc);

private:
	List<Object> ObjectList;
	POINT m_mousePos;
	Object* m_object;
	HWND m_hWnd = NULL;

};

