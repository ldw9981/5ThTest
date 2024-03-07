#pragma once

class GameEngine
{
public:
	GameEngine() {};
	~GameEngine() {};

	void Initialize();
	void Update();
	void Render();
	void Finalize();

};

