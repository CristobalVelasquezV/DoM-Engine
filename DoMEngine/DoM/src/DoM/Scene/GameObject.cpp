#include "Dompch.h"
#include "GameObject.h"
#include "Transform.h"
namespace DoM {




	GameObject::~GameObject()
	{
		
	}

	void GameObject::Start()
	{
		for each (AComponent * component in m_Components)
		{
			component->Start();
		}
	}

	void GameObject::Update()
	{
		for each (AComponent* component in m_Components)
		{
			component->Update();
		}
	}

	void GameObject::OnTriggerEnter(ColliderComponent& Collider)
	{
		for each (AComponent * component in m_Components)
		{
			component->OnTriggerEnter(Collider);
		}
	}

	void GameObject::OnTrigger(ColliderComponent& Collider)
	{
		for each (AComponent * component in m_Components)
		{
			component->OnTrigger(Collider);
		}
	}

	void GameObject::OnTriggerExit(ColliderComponent& Collider)
	{
		for each (AComponent * component in m_Components)
		{
			component->OnTriggerExit(Collider);
		}
	}

	GameObject::GameObject(std::string name) : m_Transform(Transform({ 0.0f, 0.0f, 0.0f })), m_Name(name), b_isDeleted(false)
	{

	}
	GameObject::GameObject(std::string name,glm::vec3 position) : m_Transform(Transform(position)), m_Name(name), b_isDeleted(false)
	{

	}

	GameObject::GameObject(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
		:m_Transform(Transform(position,rotation,scale)), m_Name(name), b_isDeleted(false)
	{

	}

	void Destroy(std::string name)
	{
		 SceneManager::GetActualScene().DestroyGameObjectInScene(name);
		 return;
	}

	DoM::GameObject* Instanciate(std::string name)
	{
		return SceneManager::GetActualScene().CreateGameObjectInScene(name);
	}

	DoM::GameObject* Instanciate(std::string name, glm::vec3 position)
	{
		return SceneManager::GetActualScene().CreateGameObjectInScene(name);
	}
}