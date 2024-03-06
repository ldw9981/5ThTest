#pragma once
#include "windows.h"

class Object
{
public:
	// 위치를 갖다 바로 넣을까? 
	Object(POINT _Pos) { pos = _Pos; }

	void Init() ;
	void Update() ;
	void Render(HDC _dc);

// 일단 열자
	int r= 100;	// 반지름
	POINT pos;	// 위치

};
