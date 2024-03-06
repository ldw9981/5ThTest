#pragma once
#include "MyList.h"
#include "MyCircle.h"

#include <vector>
using namespace std;

class GameLoop 
{
public:
	GameLoop();
	~GameLoop();

	void Start(HWND hwnd);
	void Render();
	void Update();
	void Finalize();

private:
	HWND m_hwnd;
	HDC m_hdc;
	HPEN m_pen;

	HBITMAP m_bitmap;
	HDC m_memDC;

	float Distance(POINT p1, POINT p2);

	MyList<MyCircle> m_circles;
	//vector<MyCircle> m_circles;
	int m_circleCount = 0;

	bool m_iscurrLB = false;
	bool m_isprevLB = false;
	bool m_iscurrRB = false;
	bool m_isprevRB = false;
};