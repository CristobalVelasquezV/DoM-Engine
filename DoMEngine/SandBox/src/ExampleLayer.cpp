#include "ExampleLayer.h"
#include "DoM/Core/Input.h"
#include "DoM/Core/KeyCodes.h"
#include "DoM/Scene/RendererComponent.h"
#include "DoM/Core/Time.h"
#include <DoM.h>
#include <imgui.h>
#include "DoM/Scene/GameObject.h"
#include "DoM/Scene/Scene.h"
#include "DoM/Scene/SceneManager.h"
#include "DoM/Scene/BoxColliderComponent.h"
#include "PlayerComponent.h"
ExampleLayer::ExampleLayer():m_OrthographicCamera(-1.6f, 1.6f, -0.9f, 0.9f),Layer("Example Layer")
{

}
DoM::GameObject* Player;
DoM::GameObject* collectable;
DoM::GameObject* collectable2;
void ExampleLayer::OnAttach()
{

	//DoM::Scene scene = DoM::Scene("Scene name");
	//DoM::SceneManager::ChangeScene(scene);
	collectable2 = DoM::SceneManager::GetActualScene().CreateGameObjectInScene("collectable2", { -1.0f,-1.0f,-1.0f }, { 1.0f,1.0f,1.0f }, { 0.1f,0.1,0.1 });
	collectable=DoM::SceneManager::GetActualScene().CreateGameObjectInScene("collectable", { 1.0f,1.0f,1.0f }, { 1.0f,1.0f,1.0f }, { 0.1f,0.1,0.1 });
	Player = DoM::SceneManager::GetActualScene().CreateGameObjectInScene("player", { 1.0f,1.0f,1.0f }, { 1.0f,1.0f,1.0f }, { 0.1f,0.1,0.1 });


	DoM::Material* mat1 = new DoM::Material({ 1.0f,0.5f,0.5f,1.0f });
	DoM::Material* mat2 = new DoM::Material({ 0.0f,1.0f,0.5f,1.0f });


	DoM::RendererComponent* rc = Player->AddComponent<DoM::RendererComponent>();
	DoM::RendererComponent* rc2 = collectable->AddComponent<DoM::RendererComponent>();
	DoM::RendererComponent* rc3 = collectable2->AddComponent<DoM::RendererComponent>();

	rc3->AssignMaterial((*mat1));
	rc->AssignMaterial((*mat2));
	rc2->AssignMaterial((*mat1));


	DoM::BoxColliderComponent* box3 = collectable2->AddComponent<DoM::BoxColliderComponent>();
	DoM::BoxColliderComponent* box2 = collectable->AddComponent<DoM::BoxColliderComponent>();
	DoM::BoxColliderComponent* box1 = Player->AddComponent<DoM::BoxColliderComponent>();
	box2->setTrigger(true);
	box3->setTrigger(true);

	PlayerComponent*pc = Player->AddComponent<PlayerComponent>();
	CollectableComponent* cc = collectable->AddComponent<CollectableComponent>();
	CollectableComponent* cc2 = collectable2->AddComponent<CollectableComponent>();



}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate()
{

	float ts = DoM::Time::GetDeltaTime();

	if (DoM::Input::IsKeyPressed(DoM::Key::A))
	{
		m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
	}
	else if (DoM::Input::IsKeyPressed(DoM::Key::D))
	{
		m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
	}

	if (DoM::Input::IsKeyPressed(DoM::Key::W))
	{
		m_CameraPosition.x += -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		m_CameraPosition.y += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
	}
	else if (DoM::Input::IsKeyPressed(DoM::Key::S))
	{
		m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		m_CameraPosition.y -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
	}

	if (m_Rotation)
	{
		if (DoM::Input::IsKeyPressed(DoM::Key::Q))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (DoM::Input::IsKeyPressed(DoM::Key::E))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		if (m_CameraRotation > 180.0f)
			m_CameraRotation -= 360.0f;
		else if (m_CameraRotation <= -180.0f)
			m_CameraRotation += 360.0f;

		m_OrthographicCamera.SetRotation(m_CameraRotation);
	}

	m_OrthographicCamera.SetPosition(m_CameraPosition);

	m_CameraTranslationSpeed = m_ZoomLevel;

	DoM::RenderCommand::SetClearColor(glm::vec4(0.1, 0.1, 0.1, 1));
	DoM::RenderCommand::Clear();
	DoM::Renderer::BeginScene(m_OrthographicCamera);

	Player->m_Transform.SetPosition(m_CameraPosition);
}

void ExampleLayer::OnImGuiRender()
{
	ImGui::Begin("Settings");
	//ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void ExampleLayer::OnEvent(DoM::Event& e)
{

}
