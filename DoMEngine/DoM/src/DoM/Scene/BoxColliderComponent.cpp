#include "Dompch.h"
#include "BoxColliderComponent.h"
#include "GameObject.h"
#include "DoM/Events/Event.h"
#include "DoM/Physics.h"
#include "glm/glm.hpp"
namespace DoM {

	void BoxColliderComponent::Awake()
	{

	}

	void BoxColliderComponent::Start()
	{

	}

	void BoxColliderComponent::Update()
	{

	}

	void BoxColliderComponent::FixedUpdate()
	{

	}

	void BoxColliderComponent::OnAttach()
	{

	}

	void BoxColliderComponent::OnDestroy()
	{
		SceneManager::GetActualScene().EraseCollider(m_id);

	}

	bool BoxColliderComponent::Collide(ColliderComponent* collider)
	{

		return collider->CollideWith(this);
	}

	bool BoxColliderComponent::CollideWith(BoxColliderComponent* collider)
	{
		float ax = m_GameObject->m_Transform.Translation.x;
		float ay = m_GameObject->m_Transform.Translation.y;
		float az = m_GameObject->m_Transform.Translation.z;

		float bx = collider->m_GameObject->m_Transform.Translation.x;
		float by = collider->m_GameObject->m_Transform.Translation.y;
		float bz = collider->m_GameObject->m_Transform.Translation.z;

		if (glm::abs(ax - bx) < (*this).m_xSize + collider->m_xSize) {
			if (glm::abs(ay - by) < (*this).m_ySize + collider->m_ySize) {
				//if (glm::abs(az - bz) < (*this).m_zSize + collider->m_zSize) {
					
				//}

				return true;
			}
		}

		return false;
	}

	BoxColliderComponent::BoxColliderComponent(GameObject& gameObject):m_zSize(0.1f),m_xSize(0.1f),m_ySize(0.1f)
	{
		m_id = s_id;
		s_id++;
		SceneManager::GetActualScene().AddColliderToScene((*this));

		m_GameObject = &gameObject;
		this->Awake();
	}


}