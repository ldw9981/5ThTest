#include "Core.h"
#include <wingdi.h>

void Core::Run(HDC hdc)
{
	Rectangle(hdc, 0, 0, 1920, 1080);

	Node<Circle>* iterator = circleList.head;
	while (iterator)
	{
		Circle circle = iterator->data;
		Ellipse(hdc, circle.left, circle.top, circle.right, circle.bottom);

		iterator = iterator->nextNode;
	}
}

void Core::CreateCircle(int x, int y, int radius)
{
	Circle circle = { x - radius, y - radius, x + radius, y + radius };

	circleList.InsertBack(circle);
}

void Core::DeleteCircle(int x, int y)
{
	Node<Circle>* iterator = circleList.head;
	while (iterator)
	{
		if ((iterator->data.left < x && iterator->data.right > x)
			&& (iterator->data.top < y && iterator->data.bottom > y))
		{
			Node<Circle>* temp = iterator->nextNode;

			circleList.DeleteNode(iterator);

			iterator = temp;
		}
		else
		{
			iterator = iterator->nextNode;
		}
	}
}
