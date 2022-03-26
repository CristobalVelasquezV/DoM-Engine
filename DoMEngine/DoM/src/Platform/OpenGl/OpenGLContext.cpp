#include "Dompch.h"
#include "Platform/OpenGl/OpenGLContext.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace DoM {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		DOM_CORE_ASSERT(windowHandle, "Window Handle Null.");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DOM_CORE_ASSERT(status, "Failed to initialize GLAD.");
		DOM_CORE_INFO("Vendor: {0}",glGetString(GL_VENDOR) );
		DOM_CORE_INFO("Renderer: {0}",glGetString(GL_RENDERER) );
		DOM_CORE_INFO("Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}