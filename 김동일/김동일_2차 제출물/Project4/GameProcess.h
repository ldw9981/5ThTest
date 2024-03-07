#pragma once

class GameEngine;
class GraphicsEngine;

class GameProcess
{
public:
	GameProcess() {};
	~GameProcess() {};

	void Initialize(HWND hWnd, float wide, float height);
	void Update();
	void Render();
	void Finalize();

public:
	GameEngine* m_gameEngine = nullptr;
	GraphicsEngine* m_graphicsEngine = nullptr;
};

