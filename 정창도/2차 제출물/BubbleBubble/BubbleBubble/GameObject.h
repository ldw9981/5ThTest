#pragma once

#include "Windows.h"
#include <math.h>
#include "Input.h"
#include "LIst.h"

class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual void Update(float deltaTime) 
	{
		if (Input::GetInstance().GetKeyDown(1))
		{
			auto pos = Input::GetInstance().GetMousePos();
			auto length = pow(Position.x - pos.x, 2) + pow(Position.y - pos.y, 2);
			if (Radius > sqrt(length))
			{
				m_DefferdDestroyer->push_back(this);
			}
		}
	};
	virtual void Render(HDC hDC) 
	{
		auto root2 = sqrt(2);
		Ellipse(hDC,
			Position.x - Radius,
			Position.y - Radius,
			Position.x + Radius,
			Position.y + Radius);
	}

public:
	POINT Position;
	float Radius = 100.f;

	Changdo::List<GameObject*>* m_DefferdDestroyer;
};

