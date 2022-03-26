#include "Dompch.h"
#include "Time.h"
#include "GLFW/glfw3.h"
namespace DoM {
	float DoM::Time::deltaTime = 0;
	float DoM::Time::m_LastFrameTime = 0;
	void Time::Tick()
	{
		{
			float time = (float)glfwGetTime();
			deltaTime = time - m_LastFrameTime;
			m_LastFrameTime = time;
		}
	}

}