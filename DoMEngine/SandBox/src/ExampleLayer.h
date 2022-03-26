#pragma once
#include "DoM.h"
#include "DoM/Renderer/Shader.h"
class ExampleLayer : public DoM::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate() override;
	virtual void OnImGuiRender() override;
	void OnEvent(DoM::Event& e) override;
private:

	DoM::OrthographicCamera m_OrthographicCamera;

private:
	float m_AspectRatio;
	float m_ZoomLevel = 1.0f;

	bool m_Rotation;

	glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
	float m_CameraRotation = 0.0f; //In degrees, in the anti-clockwise direction
	float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
};