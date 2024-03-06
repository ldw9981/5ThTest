#include "MyCircle.h"

MyCircle::MyCircle(POINT position)
:m_position(position)
{
}

MyCircle::~MyCircle()
{
}

void MyCircle::Render(HDC dc)
{
	Ellipse(dc, m_position.x - m_radius, m_position.y - m_radius,
		m_position.x + m_radius, m_position.y + m_radius);
}
