#pragma once
#include "default.h"

class Circle
{
public:
	Circle(Vector2 center);
	~Circle();

public:
	Vector2 m_Center;
	float m_Radius;
};

