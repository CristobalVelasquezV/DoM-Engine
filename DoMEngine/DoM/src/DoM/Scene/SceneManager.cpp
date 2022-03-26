#include "Dompch.h"
#include "SceneManager.h"
namespace DoM {
	
	Scene& SceneManager::GetActualScene() 
	{
		return *m_ActualScene;
	}

	void SceneManager::ChangeScene(Scene &scene)
	{
		m_ActualScene.reset(&scene);
	}

	std::unique_ptr<DoM::Scene> SceneManager::m_ActualScene = std::unique_ptr<Scene>(new Scene("Initial Scene"));

}