#pragma once

#include "AComponent.h"
#include "DoM/Scene/SceneManager.h"
namespace DoM {
	class BoxColliderComponent;

	class ColliderComponent : public AComponent {
	public:

		ColliderComponent() {
			b_isTrigger = false;
			b_isDeleated = false;
		}
		~ColliderComponent();
		virtual int GetID() = 0;
		virtual bool Collide(ColliderComponent* collider)=0;
		virtual bool CollideWith(BoxColliderComponent* collider)=0;
		bool isTrigger() { return b_isTrigger; }
		bool isDeleted() { return b_isDeleated; }
		void setTrigger(bool val) { b_isTrigger = val; }
	private:




	protected:
		static int s_id;
		int m_id;
		bool b_isTrigger;
		bool b_isDeleated;
	};
}