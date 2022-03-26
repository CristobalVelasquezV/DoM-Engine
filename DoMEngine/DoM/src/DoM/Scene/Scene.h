#pragma once
#include <map>
#include "GameObject.h"
#include <string.h>
namespace DoM {
	class GameObject;
	class ColliderComponent;
	class Scene {
		
	public:
		Scene(std::string name);
		GameObject* CreateGameObjectInScene(std::string name);
		GameObject* CreateGameObjectInScene(std::string name, glm::vec3 position);
		GameObject* CreateGameObjectInScene(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		void DestroyGameObjectInScene(std::string name);

		std::map<std::string, GameObject*>* GetGameObjectMap();
		std::map<int, ColliderComponent*>* GetColliders();
		void AddColliderToScene(ColliderComponent& ColliderComponent);
		bool EraseCollider(int id);
	private:
		std::string m_Name;
		std::map<std::string, GameObject*> * m_GameObjectMap;
		std::map<int,ColliderComponent*>* m_Colliders;
	};

}