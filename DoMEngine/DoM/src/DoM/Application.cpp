#include "Dompch.h"
#include "Application.h"
#include <GLAD/glad.h>
#include "DoM/Core/Input.h"
#include "DoM/Renderer/Buffer.h"
#include "DoM/Renderer/Shader.h"
#include "DoM/Renderer/Renderer.h"
#include "DoM/Renderer/RenderCommand.h"
#include "glm/glm.hpp"
#include "DoM/Scene/BoxColliderComponent.h"
#include "GLFW/glfw3.h"
#include "DoM/Core/Time.h"
#include "DoM/Scene/SceneManager.h"
#include <map>
#include "DoM/Physics.h"
#include <string>
namespace DoM{

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
	
	Application* Application::s_Instance = nullptr;


	Application::Application()
	{
		DOM_CORE_ASSERT(!s_Instance, "Application already exists.");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));	
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}
	Application::~Application()
	{
	}
	std::map<std::string, GameObject*>::iterator it;
	void Application::Run() {
		while (m_Running) {
			Time::Tick();

			std::map<std::string,DoM::GameObject*>* GameObjectMap = SceneManager::GetActualScene().GetGameObjectMap();

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			for (it = (*GameObjectMap).begin(); it != (*GameObjectMap).end(); it++)
			{
				if (!it->second->isDeleted()) {
					it->second->Update();
				}
	
			}
			DoM::Physics::Update();
			m_ImGuiLayer->Begin();
			for (Layer* layer:m_LayerStack){
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();


			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));


		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.m_Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}


	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}


