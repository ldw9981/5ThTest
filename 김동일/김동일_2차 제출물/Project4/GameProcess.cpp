#include "pch.h"
#include "GameProcess.h"

#include "GameEngine.h"
#include "GraphicsEngine.h"

void GameProcess::Initialize(HWND hWnd, float wide, float height)
{
	m_gameEngine = new GameEngine();
	m_graphicsEngine = new GraphicsEngine();

	m_gameEngine->Initialize();
	m_graphicsEngine->Initialize(hWnd, wide, height);
}

void GameProcess::Update()
{
	m_gameEngine->Update();
	m_graphicsEngine->Update();
}

void GameProcess::Render()
{
	m_gameEngine->Render();
	m_graphicsEngine->Render();
}

void GameProcess::Finalize()
{
	m_gameEngine->Finalize();
	m_graphicsEngine->Finalize();

	delete m_gameEngine;
	delete m_graphicsEngine;
}
