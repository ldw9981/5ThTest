#pragma once
#include <Windows.h>
#include "List.h"

class Circle;

class DemoApp
{
public:
	DemoApp();
	~DemoApp();

public:
	void SetHWND(HWND hwnd);

public:
	void Init();
	void Update();
	void Render();

public:
	void CreateCircle();
	void DeleteCircle();

public:
	HBRUSH hBrush;

	HWND m_hwnd;
	int MouseX;
	int MouseY;

	List<Circle> m_Circles;
	List<Circle> m_RenderCircles;
};

