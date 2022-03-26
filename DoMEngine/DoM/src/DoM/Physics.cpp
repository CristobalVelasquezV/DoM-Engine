#include "Dompch.h"
#include "Physics.h"
#include <map>
#include "DoM/Scene/ColliderComponent.h"
#include "DoM/Scene/SceneManager.h"
namespace DoM {
	std::map<int, ColliderComponent*>::iterator i;
	std::map<int, ColliderComponent*>::iterator j;
	void Physics::Update()
	{
		std::map<int, ColliderComponent*>* ColliderMap = SceneManager::GetActualScene().GetColliders();


		for (i = (*ColliderMap).begin();i != (*ColliderMap).end(); i++)
		{
			if (!i->second->m_GameObject->isDeleted()) {
				for (j = (*ColliderMap).begin(); j != (*ColliderMap).end(); j++)
				{
					if (!j->second->m_GameObject->isDeleted()) {
						if (i != j && i->second->Collide(j->second)) {
							if (i->second->isTrigger()) {
								j->second->m_GameObject->OnTrigger(*(i->second));
							}
							if (j->second->isTrigger()) {
								i->second->m_GameObject->OnTrigger(*(j->second));
							}
							//DOM_CORE_INFO("COL" + j->second->m_GameObject->GetName());
						}
					}

				}
			}

		}

	}



}