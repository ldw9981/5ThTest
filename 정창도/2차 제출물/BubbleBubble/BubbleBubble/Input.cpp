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

	// 키가 눌려있따. 5
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (Lbtn.bPrev) {
			// 이전 프레임에 눌려 있었다. 
			Lbtn.eState = KEY_STATE::HOLD;
		}
		else {
			// 이전 프레임에 눌려있찌 않앗따. 
			Lbtn.eState = KEY_STATE::TAP;
		}
		Lbtn.bPrev = true;
	}
	// 키가 안눌려있다. 
	else {
		if (Lbtn.bPrev) {
			// 이전 프레임에는 눌려있었따. 
			Lbtn.eState = KEY_STATE::AWAY;
		}
		else {
			// 이전 프레임에 눌려있지 않았따. 
			Lbtn.eState = KEY_STATE::NONE;
		}
		Lbtn.bPrev = false;
	}

	// 우클릭
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		if (Rbtn.bPrev) {
			// 이전 프레임에 눌려 있었다. 
			Rbtn.eState = KEY_STATE::HOLD;
		}
		else {
			// 이전 프레임에 눌려있찌 않앗따. 
			Rbtn.eState = KEY_STATE::TAP;
		}
		Rbtn.bPrev = true;
	}
	// 키가 안눌려있다. 
	else {
		if (Rbtn.bPrev) {
			// 이전 프레임에는 눌려있었따. 
			Rbtn.eState = KEY_STATE::AWAY;
		}
		else {
			// 이전 프레임에 눌려있지 않았따. 
			Rbtn.eState = KEY_STATE::NONE;
		}
		Rbtn.bPrev = false;
	}

}
