#pragma once
#include <Windows.h>


class MyCircle 
{
public:
	MyCircle(POINT position);
	~MyCircle();

	void Render(HDC dc);

	POINT m_position;
	float m_radius = 25;
};