#pragma once
#include "Dompch.h"
#include "DoM/Core.h"
#include "DoM/Events/Event.h"

namespace DoM {

	class Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImGuiRender() {}
		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;

	};
}