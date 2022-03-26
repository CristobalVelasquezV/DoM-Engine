#pragma once
#include "DoM/Core/Layer.h"
#include "DoM/Events/MouseEvent.h"
#include "DoM/Events/KeyEvent.h"
#include "DoM/Events/ApplicationEvent.h"
namespace DoM {
	class DOM_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnDetach() override;
		virtual void OnAttach() override;
		virtual void OnEvent(Event& event) override;
		virtual void OnImGuiRender() override;
		void Begin();
		void End();
		void SetDarkThemeColors();

	private:
		float m_Time = 0;

	};


}