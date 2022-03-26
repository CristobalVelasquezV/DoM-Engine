#include "Dompch.h"
#include "Scene.h"
#include "GameObject.h"
#include "ColliderComponent.h"
namespace DoM {



	Scene::Scene(std::string name):m_Name(name), m_Colliders(new std::map<int, ColliderComponent*>())
	{
		m_GameObjectMap = new std::map<std::string, GameObject*>();

	}

	DoM::GameObject* Scene::CreateGameObjectInScene(std::string name)
	{
		GameObject* go = new GameObject(name);
		auto pair = std::pair<const std::string, GameObject*>(name, go);
		auto res=m_GameObjectMap->insert(pair);

		if (!res.second) {
			DOM_CORE_ERROR("Trying to instanciate gameobject {0} in scene, already has one with same name", name);
		}
		else {

		}

		return go;
	}

	DoM::GameObject* Scene::CreateGameObjectInScene(std::string name, glm::vec3 position)
	{
		GameObject* go = new GameObject(name,position);
		auto pair = std::pair<const std::string, GameObject*>(name, go);
		auto res = m_GameObjectMap->insert(pair);

		if (!res.second) {
			DOM_CORE_ERROR("Trying to instanciate gameobject {0} in scene, already has one with same name", name);
		}
		else {

		}
		return go;
	}





	DoM::GameObject* Scene::CreateGameObjectInScene(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		GameObject* go = new GameObject(name, position,rotation,scale);
		auto pair = std::pair<const std::string, GameObject*>(name, go);
		auto res = m_GameObjectMap->insert(pair);

		if (!res.second) {
			DOM_CORE_ERROR("Trying to instanciate gameobject {0} in scene, already has one with same name", name);
		}
		else {

		}
		return go;
	}

	void Scene::DestroyGameObjectInScene(std::string name)
	{
		auto v = m_GameObjectMap->find(name);
		for each (auto comp in v->second->m_Components)
		{
			comp->OnDestroy();
		}
		auto res = m_GameObjectMap->erase(name);
	}

	std::map<std::string, GameObject*>* Scene::GetGameObjectMap()
	{
		return m_GameObjectMap;
	}

	std::map<int, ColliderComponent*>* Scene::GetColliders()
	{

		return m_Colliders;
	}

	void Scene::AddColliderToScene(ColliderComponent& colliderComponent)
	{

		auto pair = std::pair<int, ColliderComponent*>(colliderComponent.GetID(), &colliderComponent);

		auto res = m_Colliders->insert(pair);
	}

	bool Scene::EraseCollider(int id)
	{
		//auto v = m_Colliders->find(id);
		m_Colliders->erase(id);
		return true;
	}

}