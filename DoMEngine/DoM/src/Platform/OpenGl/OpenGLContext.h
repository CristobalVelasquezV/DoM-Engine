#pragma once
#include "Dompch.h"
#include "DoM/Renderer/GraphicsContext.h"
struct GLFWwindow;
namespace DoM {
	class OpenGLContext :public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow * m_WindowHandle;

	};
}