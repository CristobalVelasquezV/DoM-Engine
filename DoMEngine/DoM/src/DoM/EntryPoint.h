#pragma once
#include "DoM/Core.h"

#include "DoM/Application.h"

#ifdef DOM_PLATFORM_WINDOWS

extern DoM::Application* DoM::CreateApplication();

int main(int argc,char** argv){
	DoM::Log::Init();
	DOM_CORE_WARN("Initialize log");
	DOM_INFO("Client log");

	auto app=DoM::CreateApplication();
	app->Run();
	delete app;

}

#endif // DOM_PLATFORM_WINDOWS
