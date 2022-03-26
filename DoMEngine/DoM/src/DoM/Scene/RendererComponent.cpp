#include "Dompch.h"
#include "RendererComponent.h"
#include "GameObject.h"
#include "DoM/Renderer/Renderer.h"
namespace DoM {

	void RendererComponent::Awake()
	{

	}

	void RendererComponent::Start()
	{

	}

	void RendererComponent::Update()
	{
		if (m_Material != nullptr) {
			m_Material->UploadMaterial();
			Renderer::Submit(m_Material->m_Shader, m_Material->m_VertexArray, m_GameObject->m_Transform.GetTransform());
			Renderer::EndScene();
		}


	}

	void RendererComponent::FixedUpdate()
	{

	}

	void RendererComponent::OnAttach()
	{

	}

	void RendererComponent::OnDestroy()
	{

	}



	void RendererComponent::OnTriggerEnter(ColliderComponent& Collider)
	{

	}

	void RendererComponent::OnTrigger(ColliderComponent& Collider)
	{

	}

	void RendererComponent::OnTriggerExit(ColliderComponent& Collider)
	{

	}

	void RendererComponent::AssignMaterial(const Material& mat)
	{
		m_Material = CreateRef<Material>( mat);
	}

}