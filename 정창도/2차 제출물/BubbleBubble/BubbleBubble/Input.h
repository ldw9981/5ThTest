#pragma once
#include <windows.h>

enum class KEY_STATE {
	NONE,	// ������ �ʰ� �������� ������ ���� ����
	TAP,	// �� ���� ����
	HOLD,	// ������ �ִ�
	AWAY,	// �� �� ����

};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrev;
};

class Input
{
private:
	Input() {}
public:
	~Input() {}
	static Input& GetInstance() {
		static Input instance;
		return instance;
	}
	void Initailize();
	void Update();

	POINT GetMousePos() { return mousePos; }
	bool GetKeyDown(int mouseindex)
	{
		if (mouseindex == 0)
		{
			return Lbtn.eState == KEY_STATE::TAP;
		}
		else if (mouseindex == 1)
		{
			return Rbtn.eState == KEY_STATE::TAP;
		}
		return false;
	}

public:
	POINT mousePos;

	tKeyInfo Lbtn;
	tKeyInfo Rbtn;
};

