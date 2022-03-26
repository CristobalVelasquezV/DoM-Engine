#pragma once
#include "Scene.h"
namespace DoM {
	class Scene;
	class SceneManager {
	public:
		static Scene& GetActualScene();
		static void ChangeScene(Scene &scene);
	private:
		static std::unique_ptr<Scene> m_ActualScene;
		SceneManager();
	};
}