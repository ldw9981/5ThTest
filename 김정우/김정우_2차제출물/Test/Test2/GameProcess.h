#pragma once
#include "framework.h"
#include "../Test/LinkedList.h"
#include "Circle.h"

class GameProcess
{
public:
	GameProcess();
	~GameProcess();

	void Initialize(HWND hWnd);
	void Update();
	void Render();
	void Finalize();

	HWND hWnd = nullptr;

	POINT mousePos{};
	HDC hdc{};
	PAINTSTRUCT ps{};
	LinkedList<Circle> circles;

};

