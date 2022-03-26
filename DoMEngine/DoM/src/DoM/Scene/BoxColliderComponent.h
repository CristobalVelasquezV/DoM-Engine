#pragma once
#include "ColliderComponent.h"
#include "AComponent.h"
#include "GameObject.h"
namespace DoM {
	class AComponent;
	class ColliderComponent;

	class BoxColliderComponent : public ColliderComponent {

	private:

		void Awake() override;


		void Start() override;


		void Update() override;


		void FixedUpdate() override;


		void OnAttach() override;


		void OnDestroy() override;




		float m_xSize;
		float m_ySize;
		float m_zSize;

		bool Collide(ColliderComponent* collider) override;
		bool CollideWith(BoxColliderComponent* collider) override;
	public:

		BoxColliderComponent(GameObject& gameObject);
	

		int GetID() override { return m_id; }

	};
}