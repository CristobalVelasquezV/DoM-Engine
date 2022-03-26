#include "Dompch.h"
#include "WindowsWindow.h"
#include "DoM/Events/ApplicationEvent.h"
#include "DoM/Events/Event.h"
#include "DoM/Events/KeyEvent.h"
#include "DoM/Events/MouseEvent.h"
#include "Platform/OpenGl/OpenGLContext.h"

namespace DoM {
	static bool s_GLFWInitialized = false;
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}
	static void GLFWErrorCallback(int error,const char * description) {
		DOM_CORE_ERROR("GLFW Error ({0}: {1})", error, description);
	}
	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}
	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}
	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		DOM_CORE_INFO("Creating Windows {0} ({1},{2})", props.Title, props.Width, props.Height);
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			//DOM_CORE_WARN(success, "Could not initialize glfw.");
			glfwSetErrorCallback(GLFWErrorCallback);
		
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//set GLFW Callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);

			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			DOM_CORE_INFO("close window");
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int key, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				MouseButtonReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event = MouseScrolledEvent((float)xoffset, (float)yoffset);
			data.EventCallback(event);

		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event = MouseMovedEvent((float)xpos, (float)ypos);
			data.EventCallback(event);

		});

	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		m_Context->SwapBuffers();

	}
	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}
	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}
}