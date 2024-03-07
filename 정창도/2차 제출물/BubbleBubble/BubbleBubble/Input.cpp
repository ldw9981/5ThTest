#include "Input.h"
#include <WinUser.h>

void Input::Initailize()
{
	Lbtn.bPrev = false;
	Lbtn.eState = KEY_STATE::NONE;
	Rbtn.bPrev = false;
	Rbtn.eState = KEY_STATE::NONE;
}

void Input::Update()
{
	GetCursorPos(&mousePos);

	// Ű�� �����ֵ�. 5
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (Lbtn.bPrev) {
			// ���� �����ӿ� ���� �־���. 
			Lbtn.eState = KEY_STATE::HOLD;
		}
		else {
			// ���� �����ӿ� �������� �ʾѵ�. 
			Lbtn.eState = KEY_STATE::TAP;
		}
		Lbtn.bPrev = true;
	}
	// Ű�� �ȴ����ִ�. 
	else {
		if (Lbtn.bPrev) {
			// ���� �����ӿ��� �����־���. 
			Lbtn.eState = KEY_STATE::AWAY;
		}
		else {
			// ���� �����ӿ� �������� �ʾҵ�. 
			Lbtn.eState = KEY_STATE::NONE;
		}
		Lbtn.bPrev = false;
	}

	// ��Ŭ��
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		if (Rbtn.bPrev) {
			// ���� �����ӿ� ���� �־���. 
			Rbtn.eState = KEY_STATE::HOLD;
		}
		else {
			// ���� �����ӿ� �������� �ʾѵ�. 
			Rbtn.eState = KEY_STATE::TAP;
		}
		Rbtn.bPrev = true;
	}
	// Ű�� �ȴ����ִ�. 
	else {
		if (Rbtn.bPrev) {
			// ���� �����ӿ��� �����־���. 
			Rbtn.eState = KEY_STATE::AWAY;
		}
		else {
			// ���� �����ӿ� �������� �ʾҵ�. 
			Rbtn.eState = KEY_STATE::NONE;
		}
		Rbtn.bPrev = false;
	}

}
