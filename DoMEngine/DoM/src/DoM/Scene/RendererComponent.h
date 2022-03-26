#pragma once
#include "DoM/Scene/AComponent.h"
#include "DoM/Renderer/VertexArray.h"
#include "DoM/Renderer/Shader.h"
#include "DoM/Renderer/Material.h"
namespace DoM {

	class RendererComponent:public AComponent {

	private:
	
			virtual void Awake() override;
			virtual void Start() override;
			virtual void Update() override;
			virtual void FixedUpdate() override;
			virtual void OnAttach() override;
			virtual void OnDestroy() override;

			void OnTriggerEnter(ColliderComponent& Collider) override;


			void OnTrigger(ColliderComponent& Collider) override;

			void OnTriggerExit(ColliderComponent& Collider) override;

	public:
		RendererComponent() {

			this->Awake();
		}
		RendererComponent(GameObject& gameObject)  {
			m_GameObject = &gameObject;
			this->Awake();
		}

		RendererComponent(GameObject& gameObject,glm::vec4 color)  {
			m_GameObject = &gameObject;
			this->Awake();
		}
		void AssignMaterial(const Material& mat);
		Ref <Material> m_Material;


	};
}