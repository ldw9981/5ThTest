#include "Object.h"



void Object::Init()
{
}

void Object::Update()
{
}

void Object::Render(HDC _dc)
{
	Ellipse(_dc, pos.x, pos.y, pos.x+r, pos.y+r);

}
