#pragma once

namespace DoM {
	class GameObject;
	class ColliderComponent;

	class AComponent {
	public:

		AComponent(){

		}
		GameObject* m_GameObject;
		
	private:

		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void FixedUpdate() {};
		virtual void OnAttach() {};
		virtual void OnDestroy() {};
		virtual void OnTriggerEnter(ColliderComponent& Collider) {};

		virtual void OnTrigger(ColliderComponent& Collider) {};

		virtual void OnTriggerExit(ColliderComponent& Collider) {};
		friend class GameObject;
		friend class Scene;

	};
}