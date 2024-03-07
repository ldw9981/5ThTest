#pragma once
#include "SingleTon.h"
#include <windows.h>

class MouseManager : public Singleton<MouseManager>
{
public:
	MouseManager();
	~MouseManager();

	void Update();

private:
	POINT m_mousePos;

};

