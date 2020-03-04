#include <Vaky.h>

class Sandbox : public Vaky::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}
};

Vaky::Application* Vaky::CreateApplication()
{
	return new Sandbox();
}