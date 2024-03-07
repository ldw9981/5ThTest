#pragma once

#include <Windows.h>
#include "list.h"
#include "Circle.h"

class CircleDraw
{
public:
	CircleDraw(HWND hwnd)
		:hwnd(hwnd), circleList{},isEnd(false)
		,prevLMouse(false),prevRMouse(false)
		,mousePosX(0.f),mousePosY(0.f),memDC()
	{}

	~CircleDraw()
	{
		circleList.clear();
	}

	void Initialize();

	void Finalize();

	void Update();

	void Render();

	bool IsEnd()const { return isEnd; }

private:
	void AddCircle(float x, float y, float radius);
	void DeleteCircles(float x, float y);

	void UpdateMousePosition();

private:
	static constexpr float circleRadius = 50.f;

	bool prevLMouse;
	bool prevRMouse;

	float mousePosX;
	float mousePosY;

	HWND hwnd;
	HDC memDC;
	HDC mainDC;
	my::list<Circle> circleList;

	bool isEnd;
};

