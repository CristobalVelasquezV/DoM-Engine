#include "PlayerComponent.h"

PlayerComponent::PlayerComponent(DoM::GameObject& gameObject)
{
	m_GameObject = &gameObject;
	m_TotalCollectables = 2;
	m_ActualCollectables = 0;
}

void PlayerComponent::Start()
{

}

void PlayerComponent::Update()
{

}

void PlayerComponent::FixedUpdate()
{

}

void PlayerComponent::OnTrigger(DoM::ColliderComponent& Collider)
{
	if (!Collider.isDeleted()) {
		CollectableComponent* col = Collider.m_GameObject->GetComponent<CollectableComponent>();
		Collect(col);
	}
	else {

	}

}

void PlayerComponent::Collect(CollectableComponent*& collectable)
{
	if (collectable != nullptr) {
		collectable->m_GameObject->SetDeleted();

		m_ActualCollectables++;
		DOM_CORE_INFO("grabcollectable!. {0}", m_ActualCollectables);
		if (m_ActualCollectables >= m_TotalCollectables) {
			DOM_CORE_INFO("you win.");
		}
	}
}


