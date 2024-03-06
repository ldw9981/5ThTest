#pragma once
#include "framework.h"
#include "LinekdList.h"

//class LinkedList;

class GameLoop
{
public:
	GameLoop(HWND _hWnd);
	~GameLoop();

public:
	void Init();
	void Render();
	void Update();

public:
	void DrawCircle();
	void DeleteCircle();

	void CheckOBB();

private:
	//LinkedList<float>* circlelist;
	HWND hWnd;
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH hBrush;

public:
	bool isLeftMouseClick;
	bool isRightMouseClick;

	bool isCircleDraw;

	float mousePointx;
	float mousePointy;


};

