#include <Yatagarasu.h>

class Sandbox : public Yatagarasu::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Yatagarasu::Application* Yatagarasu::CreateApplication()
{
	return new Sandbox();
}