#include <DoM.h>


class Sandbox:public DoM::Application {

public:
	Sandbox(){}

	~Sandbox()
	{

	}
};


DoM::Application* CreateApplication(){
	return new Sandbox();
}