#pragma once
#include "Core.h"
namespace DoM{
	class DOM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		
	};
	Application* CreateApplication();
}

