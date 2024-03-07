#pragma once

class GameApp
{
public:
	static GameApp* GetInstance()
	{
		static GameApp instance;
		return &instance;
	}

private:
	GameApp() = default;
	~GameApp() {}

public:
	void Init(HWND hwnd, POINT resolution);
	void Update();
	void Render();

private:
	HWND m_hWnd;
	HDC m_hdc;
	POINT m_resolution;
};

