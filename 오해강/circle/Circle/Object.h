#pragma once
#include "windows.h"

class Object
{
public:
	// ��ġ�� ���� �ٷ� ������? 
	Object(POINT _Pos) { pos = _Pos; }

	void Init() ;
	void Update() ;
	void Render(HDC _dc);

// �ϴ� ����
	int r= 100;	// ������
	POINT pos;	// ��ġ

};
