#pragma once

#ifdef DOM_PLATFORM_WINDOWS

extern DoM::Application* DoM::CreateApplication();

int main(int argc,char** argv){
	auto app=DoM::CreateApplication();
	app->Run();
	delete app;

}

#endif // DOM_PLATFORM_WINDOWS
