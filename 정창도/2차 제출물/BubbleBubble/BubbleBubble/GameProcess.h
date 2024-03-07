#pragma once
#include "List.h"
#include <Windows.h>

class GameObject;

class GameProcess
{
public:
	GameProcess() = default;
	~GameProcess();
	void Initailize(HWND hWnd);

	void Loop()
	{
		Update();
		Render();
		
		auto iter = m_DefferdDestroyer.begin();
		for (; iter != m_DefferdDestroyer.end(); ++iter)
		{
			m_Scene.erase(m_Scene.find_if(m_Scene.begin(), m_Scene.end(),
				[&iter](GameObject* go)
				{
					if (go == (*iter))
					{
						delete go;
						return true;
					}
					else
					{
						return false;
					}
				}
			));
		}
		m_DefferdDestroyer.clear();
	}
	void Update();
	void Render();


private:
	Changdo::List<GameObject*> m_Scene;
	HWND m_hWnd;
	HDC m_hDC;
	HBITMAP m_hBit;
	HDC m_memDC;

	Changdo::List<GameObject*> m_DefferdDestroyer;

};

