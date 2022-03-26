#pragma once
#include "Transform.h"
#include <string>
#include "AComponent.h"
#include "SceneManager.h"
namespace DoM {

	class GameObject
	{

	public:
		~GameObject();
		Transform m_Transform;
		std::vector<AComponent*> m_Components;
		std::string GetName() { return m_Name; }
		template <class T, typename... Args>
		T* AddComponent(Args&&... args) {
			T* ret = new T(( * this), std::forward<Args>(args)...);
			m_Components.push_back(ret);
			return ret;
		}
		template <class T>
		T* GetComponent() {
			for each (AComponent* var in m_Components)
			{
				if (T* ptr = dynamic_cast<T*>(var))
					return ptr;
			}

			return nullptr;
		}
	public:
		bool isDeleted() { return b_isDeleted; }
		void SetDeleted() { b_isDeleted = true; }

	private:
		void Awake();
		void Start();
		void Update();
		void OnTriggerEnter(ColliderComponent& Collider);
		void OnTrigger(ColliderComponent& Collider);
		void OnTriggerExit(ColliderComponent& Collider);
		bool b_isDeleted;
		GameObject(std::string name);
		GameObject(std::string name, glm::vec3 position);
		GameObject(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	


		std::string m_Name;

	friend class Scene;
	friend class Application;
	friend class RendererComponent;
	friend class Physics;
	};

	void Destroy(std::string name);
	static GameObject* Instanciate(std::string name);
	static GameObject* Instanciate(std::string name, glm::vec3 position);
}