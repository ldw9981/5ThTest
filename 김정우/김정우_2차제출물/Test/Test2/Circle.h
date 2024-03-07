#pragma once
#include <windows.h>

class Circle
{
public:
	Circle(HWND hWnd, float left, float top, float right, float bottom);
	~Circle() = default;
	void DeleteCircle();
	void Render();

	float left{};
	float top{};
	float right{};
	float bottom{};
	bool isDeleted = false;
	HWND hWnd{};
	
};

