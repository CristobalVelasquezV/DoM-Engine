#include "Dompch.h"
#include "ColliderComponent.h"
namespace DoM {

	ColliderComponent::~ColliderComponent()
	{
		DOM_CORE_INFO("COLLIDER DESTROYED");

		b_isDeleated = true;
	}

	int ColliderComponent::s_id = 0;

}