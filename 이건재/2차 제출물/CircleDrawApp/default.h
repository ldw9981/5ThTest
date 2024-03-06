#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2 operator+(const Vector2& other)
	{
		return Vector2{ this->x + other.x, this->y + other.y };
	}
};