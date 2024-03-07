#pragma once



class Circle
{
public:
	Circle()
		:x(0.f), y(0.f), radius(0.f)
	{}

	Circle(float x, float y, float radius)
		:x(x),y(y),radius(radius)
	{}

	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetRadius()const { return radius; }

private:
	float x;
	float y;
	float radius;
};
