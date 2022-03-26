#include <DoM.h>
#include <DoM/EntryPoint.h>
#include "ExampleLayer.h"
class Sandbox :public DoM::Application {

public:
	Sandbox() {
		 PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


DoM::Application* DoM::CreateApplication() {
	return new Sandbox();
}