#pragma once

#ifdef VK_PLATFORM_WINDOWS

extern Vaky::Application* Vaky::CreateApplication();

int main(int argc, char** argv) 
{
	Vaky::Log::Init();
	VK_CORE_WARN("Init warn");

	int x = 69;
	VK_INFO("Var = {0}", x);

	auto app = Vaky::CreateApplication();
	app->Run();
	delete app;
}

#endif