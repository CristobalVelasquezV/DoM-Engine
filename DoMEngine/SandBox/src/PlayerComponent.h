#pragma once
#include "DoM.h"
#include "CollectableComponent.h"
class PlayerComponent : public DoM::AComponent {

public:
	PlayerComponent(DoM::GameObject& gameObject);

	void Start() override;


	void Update() override;

	void FixedUpdate() override;

	void OnTrigger(DoM::ColliderComponent& Collider) override;
	void Collect(CollectableComponent*& collectable);
private:
	int m_TotalCollectables;
	int m_ActualCollectables;
};