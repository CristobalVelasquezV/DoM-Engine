#pragma once
#include "Dompch.h"
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "DoM/Core/LayerStack.h"
#include "DoM/ImGui/ImGuiLayer.h"
#include "DoM/Renderer/Shader.h"
#include "DoM/Renderer/VertexArray.h"
#include "DoM/Renderer/Buffer.h"
#include "DoM/Renderer/OrthographicCamera.h"

namespace DoM{
	class DOM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

	private:

		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};


	 Application* CreateApplication();

}

